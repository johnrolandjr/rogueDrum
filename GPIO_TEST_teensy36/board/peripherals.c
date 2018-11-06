/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v4.1
processor: MK66FX1M0xxx18
package_id: MK66FX1M0VMD18
mcu_data: ksdk2_0
processor_version: 4.0.0
functionalGroups:
- name: BOARD_InitPeripherals
  called_from_default_init: true
  selectedCore: core0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'system'
- type_id: 'system_54b53072540eeeb8f8e9343e71f28176'
- global_system_definitions: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "peripherals.h"
#include "led_driver.h"

extern uint8_t screen_para_out[NUM_BITS_PER_STRIP];
/***********************************************************************************************************************
 * BOARD_InitPeripherals functional group
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * dual_pwm initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'dual_pwm'
- type: 'tpm'
- mode: 'EdgeAligned'
- type_id: 'tpm_e7472ea12d53461b8d293488f3ed72ec'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'TPM1'
- config_sets:
  - tpm_main_config:
    - tpm_config:
      - clockSource: 'kTPM_SystemClock'
      - tpmSrcClkFreq: 'BOARD_BootClockRUN'
      - prescale: 'kTPM_Prescale_Divide_1'
      - timerFrequency: '10000'
      - useGlobalTimeBase: 'false'
      - triggerSelect: 'kTPM_Trigger_Select_0'
      - triggerSource: 'kTPM_TriggerSource_Internal'
      - enableDoze: 'false'
      - enableDebugMode: 'false'
      - enableReloadOnTrigger: 'false'
      - enableStopOnOverflow: 'false'
      - enableStartOnTrigger: 'false'
      - enablePauseOnTrigger: 'false'
    - timer_interrupts: 'kTPM_TimeOverflowInterruptEnable'
    - enable_irq: 'true'
    - tpm_interrupt:
      - IRQn: 'TPM1_IRQn'
      - enable_priority: 'false'
      - enable_custom_name: 'false'
    - EnableTimerInInit: 'true'
  - tpm_edge_aligned_mode:
    - tpm_edge_aligned_channels_config:
      - 0:
        - edge_aligned_mode: 'kTPM_EdgeAlignedPwm'
        - edge_aligned_pwm:
          - chnlNumber: 'kTPM_Chnl_0'
          - level: 'kTPM_NoPwmSignal'
          - dutyCyclePercent: '32'
          - enable_chan_irq: 'true'
      - 1:
        - edge_aligned_mode: 'kTPM_EdgeAlignedPwm'
        - edge_aligned_pwm:
          - chnlNumber: 'kTPM_Chnl_1'
          - level: 'kTPM_NoPwmSignal'
          - dutyCyclePercent: '67'
          - enable_chan_irq: 'true'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const tpm_config_t dual_pwm_config = {
  .prescale = kTPM_Prescale_Divide_1,
  .useGlobalTimeBase = false,
  .triggerSelect = kTPM_Trigger_Select_0,
  .triggerSource = kTPM_TriggerSource_Internal,
  .enableDoze = false,
  .enableDebugMode = false,
  .enableReloadOnTrigger = false,
  .enableStopOnOverflow = false,
  .enableStartOnTrigger = false,
  .enablePauseOnTrigger = false
};

const tpm_chnl_pwm_signal_param_t dual_pwm_pwmSignalParams[] = { 
  {
    .chnlNumber = kTPM_Chnl_0,
    .level = kTPM_NoPwmSignal,
    .dutyCyclePercent = 32
  },
  {
    .chnlNumber = kTPM_Chnl_1,
    .level = kTPM_NoPwmSignal,
    .dutyCyclePercent = 67
  }
};

uint32_t led_bit_count_g=0;
void TPM1_IRQHandler(void)
{
	int flags;
	if(led_bit_count_g < NUM_BITS_PER_STRIP)
	{
		flags = TPM_GetStatusFlags(DUAL_PWM_PERIPHERAL);
		if(flags & TPM_STATUS_CH1F_MASK)
		{
			GPIOD->PCOR = 0xFF;
		}
		else if(flags & TPM_STATUS_CH0F_MASK)
		{
			GPIOD->PDOR = screen_para_out[led_bit_count_g++];
		}
		else if(flags & TPM_STATUS_TOF_MASK)
		{
			led_bit_count_g++;
			if(led_bit_count_g > 0)
				GPIOD->PSOR = 0xFF;
		}
	}else
	{
		TPM_StopTimer(DUAL_PWM_PERIPHERAL);
	}

	TPM_ClearStatusFlags(DUAL_PWM_PERIPHERAL, (kTPM_Chnl0InterruptEnable | kTPM_Chnl1InterruptEnable | kTPM_TimeOverflowInterruptEnable));
}

void dual_pwm_init(void) {
  TPM_Init(DUAL_PWM_PERIPHERAL, &dual_pwm_config);
  TPM_SetupPwm(DUAL_PWM_PERIPHERAL, dual_pwm_pwmSignalParams, sizeof(dual_pwm_pwmSignalParams) / sizeof(tpm_chnl_pwm_signal_param_t), kTPM_EdgeAlignedPwm, 50000U, DUAL_PWM_CLOCK_SOURCE);
  TPM_EnableInterrupts(DUAL_PWM_PERIPHERAL, kTPM_Chnl0InterruptEnable | kTPM_Chnl1InterruptEnable | kTPM_TimeOverflowInterruptEnable);
  /* Enable interrupt TPM1_IRQn request in the NVIC */
  EnableIRQ(DUAL_PWM_IRQN);
}

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals(void)
{
  /* Initialize components */
  dual_pwm_init();
}

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void)
{
  BOARD_InitPeripherals();
}

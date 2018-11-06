/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

#define SOPT9_TPM1CH0SRC_TPM 0x00u /*!<@brief TPM1 channel 0 input capture source select: TPM1_CH0 signal */

/*! @name PORTD0 (coord A5), led0
  @{ */
#define BOARD_INITPINS_led0_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_led0_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_led0_PIN 0U     /*!<@brief PORTD pin index: 0 */
                                       /* @} */

/*! @name PORTD1 (coord D4), led1
  @{ */
#define BOARD_INITPINS_led1_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_led1_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_led1_PIN 1U     /*!<@brief PORTD pin index: 1 */
                                       /* @} */

/*! @name PORTD2 (coord C4), led2
  @{ */
#define BOARD_INITPINS_led2_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_led2_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_led2_PIN 2U     /*!<@brief PORTD pin index: 2 */
                                       /* @} */

/*! @name PORTD3 (coord B4), led3
  @{ */
#define BOARD_INITPINS_led3_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_led3_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_led3_PIN 3U     /*!<@brief PORTD pin index: 3 */
                                       /* @} */

/*! @name PORTD4 (coord A4), led4
  @{ */
#define BOARD_INITPINS_led4_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_led4_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_led4_PIN 4U     /*!<@brief PORTD pin index: 4 */
                                       /* @} */

/*! @name PORTD5 (coord A3), led5
  @{ */
#define BOARD_INITPINS_led5_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_led5_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_led5_PIN 5U     /*!<@brief PORTD pin index: 5 */
                                       /* @} */

/*! @name PORTD6 (coord A2), led6
  @{ */
#define BOARD_INITPINS_led6_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_led6_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_led6_PIN 6U     /*!<@brief PORTD pin index: 6 */
                                       /* @} */

/*! @name PORTD7 (coord A1), led7
  @{ */
#define BOARD_INITPINS_led7_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_led7_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_led7_PIN 7U     /*!<@brief PORTD pin index: 7 */
                                       /* @} */

/*! @name PORTC5 (coord D8), brd_led
  @{ */
#define BOARD_INITPINS_brd_led_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_brd_led_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_brd_led_PIN 5U     /*!<@brief PORTC pin index: 5 */
                                          /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
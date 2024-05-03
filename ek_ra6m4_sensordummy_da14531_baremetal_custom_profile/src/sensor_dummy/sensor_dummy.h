/*******************************************************************************************************************//**
 * @addtogroup SensorDummy
 * @{
 **********************************************************************************************************************/

#ifndef SensorDummy_H
#define SensorDummy_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#if defined(__CCRX__) || defined(__ICCRX__) || defined(__RX__)
 #error "Not supported"
#elif defined(__CCRL__) || defined(__ICCRL__) || defined(__RL78__)
 #error "Not supported"
#else
#include "rm_comms_api.h"
/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER
#endif

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @endcond */

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/
fsp_err_t SensorDummy_init(const rm_comms_instance_t *p_i2c);
fsp_err_t SensorDummy_read(const rm_comms_instance_t *p_i2c,
		uint8_t *p_dummy_data);

#if defined(__CCRX__) || defined(__ICCRX__) || defined(__RX__)
#elif defined(__CCRL__) || defined(__ICCRL__) || defined(__RL78__)
#else

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_FOOTER
#endif

#endif                                 /* SensorDummy_H_*/

/*******************************************************************************************************************//**
 * @} (end addtogroup SensorDummy)
 **********************************************************************************************************************/
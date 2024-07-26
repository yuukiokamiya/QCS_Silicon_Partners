/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "sensor_dummy.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define SENSOR_DUMMY_TIMEOUT 1000uL

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global function prototypes
 **********************************************************************************************************************/
void sensor_dummy_callback(rm_comms_callback_args_t *p_args);

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
fsp_err_t sensor_dummy_getdata(const rm_comms_instance_t *p_i2c, uint8_t *p_id);
fsp_err_t sensor_dummy_writeReg(const rm_comms_instance_t *p_i2c, uint8_t reg,
		uint8_t *p_data);
/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/
#if (BSP_CFG_RTOS == 0)
static bool g_comm_i2c_flag = false;
static rm_comms_event_t g_comm_i2c_event;
#endif
/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/
fsp_err_t SensorDummy_init(const rm_comms_instance_t *p_i2c) {
	uint8_t val = 20;
	sensor_dummy_writeReg(p_i2c, 0x10, &val);
	return FSP_SUCCESS;
}

fsp_err_t SensorDummy_read(const rm_comms_instance_t *p_i2c,
		uint8_t *p_dummy_data) {
	uint8_t id;
	sensor_dummy_getdata(p_i2c, &id);
	*p_dummy_data = id;
	return FSP_SUCCESS;
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

fsp_err_t sensor_dummy_getdata(const rm_comms_instance_t *p_i2c,
		uint8_t *p_data) {
	FSP_PARAMETER_NOT_USED(p_i2c);
	/******************** Example on how to read data from i2c *******************************************************************************/
	// rm_comms_write_read_params_t write_read_params;
	// fsp_err_t err;
	// uint8_t reg;
	// uint8_t read_data;
	// reg = SENSOR_ID_REG;
	// write_read_params.p_src      = &reg;
	// write_read_params.src_bytes  = 1;
	// write_read_params.p_dest     = &read_data;
	// write_read_params.dest_bytes = 1;
	// err = sensor_dummy_read(p_i2c, write_read_params);
	// FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
	*p_data = 10;
	return FSP_SUCCESS;
}

fsp_err_t sensor_dummy_writeReg(const rm_comms_instance_t *p_i2c, uint8_t reg,
		uint8_t *p_data) {
	FSP_PARAMETER_NOT_USED(p_i2c);
	FSP_PARAMETER_NOT_USED(reg);
	FSP_PARAMETER_NOT_USED(p_data);
	/******************** Example on how to write data on a specific register *******************************************************************************/
	// uint8_t write_data[2];
	// write_data[0] = reg;
	// write_data[1] =  (uint8_t)(p_data);
	// return sensor_dummy_write(p_i2c, write_data, sizeof(write_data));
	return FSP_SUCCESS;
}
/*******************************************************************************************************************//**
 * @brief callback function called in the I2C Communications Middleware callback function.
 **********************************************************************************************************************/
void sensor_dummy_callback(rm_comms_callback_args_t *p_args) {
#if (BSP_CFG_RTOS > 0)
    FSP_PARAMETER_NOT_USED(p_args);
#else
	/* Set event */
	switch (p_args->event) {
	case RM_COMMS_EVENT_OPERATION_COMPLETE: {
		g_comm_i2c_event = RM_COMMS_EVENT_OPERATION_COMPLETE;
		g_comm_i2c_flag = true;
		break;
	}

	case RM_COMMS_EVENT_ERROR:
		g_comm_i2c_event = RM_COMMS_EVENT_ERROR;
		break;
	default: {
		break;
	}
	}
#endif
}

///*******************************************************************************************************************//**
// * @brief Delay some microseconds.
// *
// * @retval FSP_SUCCESS              successfully configured.
// **********************************************************************************************************************/
//static fsp_err_t sensor_dummy_delay_us (uint32_t const delay_us)
//{
//    /* Software delay */
//    R_BSP_SoftwareDelay(delay_us, BSP_DELAY_UNITS_MICROSECONDS);
//
//    return FSP_SUCCESS;
//}
//
///*******************************************************************************************************************//**
// * @brief Read data from Sensor Dummy device.
// *
// * @retval FSP_SUCCESS              Successfully started.
// * @retval FSP_ERR_TIMEOUT          communication is timeout.
// * @retval FSP_ERR_ABORTED          communication is aborted.
// **********************************************************************************************************************/
//static fsp_err_t sensor_dummy_read (const rm_comms_instance_t *  p_i2c, rm_comms_write_read_params_t write_read_params)
//{
//    fsp_err_t err = FSP_SUCCESS;
//
//    /* WriteRead data */
//    err = p_i2c->p_api->writeRead(p_i2c->p_ctrl, write_read_params);
//    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
//
//#if (BSP_CFG_RTOS == 0)
//    uint16_t counter = 0;
//    g_comm_i2c_flag = false;
//    /* Wait callback */
//    while (false == g_comm_i2c_flag)
//    {
//        sensor_dummy_delay_us(1000);
//        counter++;
//        FSP_ERROR_RETURN(SENSOR_DUMMY_TIMEOUT >= counter, FSP_ERR_TIMEOUT);
//    }
//    /* Check callback event */
//    FSP_ERROR_RETURN(RM_COMMS_EVENT_OPERATION_COMPLETE == g_comm_i2c_event, FSP_ERR_ABORTED);
//#endif
//
//    return FSP_SUCCESS;
//}
//
///*******************************************************************************************************************//**
// * @brief Write data to Sensor Dummy device.
// *
// * @retval FSP_SUCCESS              Successfully started.
// * @retval FSP_ERR_TIMEOUT          communication is timeout.
// * @retval FSP_ERR_ABORTED          communication is aborted.
// **********************************************************************************************************************/
//static fsp_err_t sensor_dummy_write (const rm_comms_instance_t *  p_i2c, uint8_t * const p_src, uint8_t const bytes)
//{
//    fsp_err_t err = FSP_SUCCESS;
//
//    /* Write data */
//    err = p_i2c->p_api->write(p_i2c->p_ctrl, p_src, (uint32_t) bytes);
//    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
//#if (BSP_CFG_RTOS == 0)
//    uint16_t counter = 0;
//    g_comm_i2c_flag = false;
//    /* Wait callback */
//    while (false == g_comm_i2c_flag)
//    {
//        sensor_dummy_delay_us(1000);
//        counter++;
//        FSP_ERROR_RETURN(SENSOR_DUMMY_TIMEOUT >= counter, FSP_ERR_TIMEOUT);
//    }
//    /* Check callback event */
//    FSP_ERROR_RETURN(RM_COMMS_EVENT_OPERATION_COMPLETE == g_comm_i2c_event, FSP_ERR_ABORTED);
//#endif
//
//    return FSP_SUCCESS;
//}


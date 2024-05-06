#ifndef SENSORDUMMY_SENSOR_H_
#define SENSORDUMMY_SENSOR_H_

#include "common_utils.h"
#if (BSP_CFG_RTOS > 0)
#include "sensor_thread.h"
#endif
#include "sensor_dummy/sensor_dummy.h"

void g_dummy_quick_setup(void);
void g_dummy_sensor0_read(float *p_dummy_data);

#endif /* AS7331_SENSOR_H_ */

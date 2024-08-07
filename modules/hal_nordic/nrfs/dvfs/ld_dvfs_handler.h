/*
 * Copyright (c) 2024 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef LD_DVFS_HANDLER_H
#define LD_DVFS_HANDLER_H

#include <dvfs_oppoint.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Function to request LD frequency change.
 *
 * @param frequency requested frequency setting from enum dvfs_frequency_setting.
 * @return EBUSY                  Frequency change request pending.
 * @return EAGAIN                 DVFS init in progress.
 * @return ENXIO                  Not supported frequency settings.
 * @return NRFS_SUCCESS           Request sent successfully.
 * @return NRFS_ERR_INVALID_STATE Service is uninitialized.
 * @return NRFS_ERR_IPC           Backend returned error during request sending.
 */
int32_t dvfs_service_handler_change_freq_setting(enum dvfs_frequency_setting freq_setting);

/**
 * @brief Type to use as callback function in dvfs service
 *
 * @param new_setting applied frequency setting
 */
typedef void (*dvfs_service_handler_callback)(enum dvfs_frequency_setting new_setting);

/**
 * @brief Register callback function which will be called when new dvfs frequency is applied.
 *
 * @param clb dvfs_service_handler_callback to register
 */
void dvfs_service_handler_register_freq_setting_applied_callback(dvfs_service_handler_callback clb);

#ifdef __cplusplus
}
#endif

#endif /* LD_DVFS_HANDLER_H */

/**
 * @file tvc.h
 * @brief Thrust Vector Control — Interface
 * 
 * Controle de atitude via gimbaling do motor.
 * 2 DOF: pitch + yaw
 */

#ifndef TVC_H
#define TVC_H

#include <stdint.h>

#define TVC_MAX_DEFLECTION_DEG  8.0f
#define TVC_MAX_DEFLECTION_RAD  0.1396f  /* 8° em radianos */

/** Inicializa servos e calibra */
int tvc_init(void);

/** Define deflexão em pitch/yaw (radianos) */
int tvc_set_deflection(float pitch_rad, float yaw_rad);

/** Retorna deflexão atual */
void tvc_get_deflection(float *pitch_rad, float *yaw_rad);

/** Self-test: move servos para posições conhecidas */
int tvc_self_test(void);

#endif /* TVC_H */

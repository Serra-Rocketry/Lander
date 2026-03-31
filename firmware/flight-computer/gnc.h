/**
 * @file gnc.h
 * @brief Guidance, Navigation & Control — Interface
 * 
 * Fusão sensorial (EKF) e controle de trajetória.
 */

#ifndef GNC_H
#define GNC_H

#include <stdint.h>

/** Estado estimado do veículo */
typedef struct {
    float pos_ned[3];       /* Posição NED (m) */
    float vel_ned[3];       /* Velocidade NED (m/s) */
    float quat[4];          /* Atitude quaternion (w,x,y,z) */
    float gyro_bias[3];     /* Bias do giroscópio (rad/s) */
} gnc_state_t;

/** Inicializa filtros e sensores */
int gnc_init(void);

/** Atualiza estado estimado com leituras de sensores */
int gnc_update(void);

/** Retorna estado estimado */
const gnc_state_t* gnc_get_state(void);

/** Detecta apogeu */
int gnc_detect_apogee(void);

#endif /* GNC_H */

/**
 * @file main.c
 * @brief Serra Lander — Flight Computer
 * 
 * Arquivo principal do flight computer do Serra Lander.
 * Este é um esqueleto para referência — o firmware real será
 * desenvolvido quando o MCU for selecionado.
 */

#include <stdint.h>
#include <stdbool.h>

/* ========================================
 * Configuração
 * ======================================== */

#define CONTROL_LOOP_HZ     100
#define CONTROL_LOOP_US     (1000000 / CONTROL_LOOP_HZ)

/* Estados de voo */
typedef enum {
    STATE_IDLE,
    STATE_ARMED,
    STATE_LIFTOFF,
    STATE_ASCENT,
    STATE_APOGEE,
    STATE_DESCENT,
    STATE_FLARE,
    STATE_TOUCHDOWN,
    STATE_SAFE,
    STATE_ABORT
} flight_state_t;

/* Estado do veículo (estimado por EKF) */
typedef struct {
    float position[3];      /* NED: North, East, Down (m) */
    float velocity[3];      /* NED: m/s */
    float attitude[4];      /* Quaternion: w, x, y, z */
    float angular_rate[3];  /* Body frame: rad/s */
} vehicle_state_t;

/* Comando de controle */
typedef struct {
    float tvc_pitch;        /* rad */
    float tvc_yaw;          /* rad */
    float throttle;         /* 0.0 - 1.0 */
} control_command_t;

/* ========================================
 * Funções (declarações — implementar por módulo)
 * ======================================== */

/** Inicialização de hardware */
void avionics_init(void);

/** Leitura de sensores e fusão sensorial */
void gnc_update_state(vehicle_state_t *state);

/** Controle de atitude (PID/MPC) */
void tvc_compute_command(
    const vehicle_state_t *state,
    const flight_state_t flight_state,
    control_command_t *cmd
);

/** Aplicação de comando nos atuadores */
void tvc_apply_command(const control_command_t *cmd);

/** Verificação de transição de estado */
flight_state_t check_state_transition(
    const vehicle_state_t *state,
    flight_state_t current
);

/** Log de telemetria */
void avionics_log(const vehicle_state_t *state, flight_state_t st);

/* ========================================
 * Loop principal (state machine)
 * ======================================== */

int main(void) {
    avionics_init();
    
    flight_state_t state = STATE_IDLE;
    vehicle_state_t vehicle = {0};
    control_command_t cmd = {0};
    
    while (1) {
        /* 1. Leitura de sensores + fusão */
        gnc_update_state(&vehicle);
        
        /* 2. Verificação de transição */
        state = check_state_transition(&vehicle, state);
        
        /* 3. Controle de atitude */
        tvc_compute_command(&vehicle, state, &cmd);
        
        /* 4. Atuação */
        tvc_apply_command(&cmd);
        
        /* 5. Telemetria */
        avionics_log(&vehicle, state);
        
        /* 6. Tratamento de abort */
        if (state == STATE_ABORT) {
            /* Deploy paraquedas, desligar motor */
            break;
        }
        
        /* Timing do loop — IMPLEMENTAR */
        /* delay_us(CONTROL_LOOP_US); */
    }
    
    return 0;
}

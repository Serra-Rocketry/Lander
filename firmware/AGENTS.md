# AGENTS.md — Firmware

Convenções para desenvolvimento do firmware do flight computer do Serra Lander.

## Linguagem e Plataforma

- **Linguagem:** C/C++ (Arduino/PlatformIO ou bare-metal STM32)
- **MCU:** TBD (candidatos: ESP32, STM32, Teensy 4.x) — NÃO assumir até decisão documentada

## Arquitetura

- State machine de voo: `ARMED → LIFTOFF → ASCENT → APOGEE → DESCENT → LANDING`
- Fusão sensorial: Kalman Filter (EKF) para estado do veículo
- Controle: PID ou MPC para atitude via TVC
- Loop de controle: >100 Hz

## Code Style (C/C++)

- Prefixo de módulo: `tvc_`, `gnc_`, `avionics_`, `landing_`
- Constantes: `UPPER_SNAKE_CASE`
- Funções: `lower_snake_case`
- Structs: `PascalCase`
- Comentários em inglês
- Headers com include guards ou `#pragma once`

## Critical Don'ts

- NUNCA use `malloc`/`free` após inicialização
- NUNCA use `printf`/`Serial.print` em loops de controle críticos
- NUNCA acesse periféricos diretamente — use HAL/drivers próprios
- NUNCA use float point em ISRs
- NUNCA bloqueie o loop principal — use state machine não-bloqueante

## Testing

- Testes de unidade em `firmware/tests/` (se aplicável)
- Bench tests antes de integração: TVC isolado, sensores isolados
- Validar sempre em hardware — simulação não substitui teste físico

---

> **Para o AI assistant:** Ao trabalhar neste subsistema, sugira updates a este AGENTS.md quando:
> - Novos padrões de código forem adotados
> - Novos módulos forem criados (adicionar prefixo à lista)
> - Novas regras de segurança forem identificadas
> - Decisões de arquitetura forem tomadas

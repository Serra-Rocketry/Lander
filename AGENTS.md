# AGENTS.md — Serra Lander

Guia para AI coding assistants que trabalham neste repositório.

## Project Overview

**Serra Lander** é um veículo lander VTOL para o Lander Challenge da LASC 2026 (setembro/2026, Iacanga-SP). Projeto open-source do Serra Rocketry / LaRA-IPRJ/UERJ.

Missão: decolar verticalmente, atingir 50 m AGL, descer controlado e pousar propulsivamente sem paraquedas.

Configuração escolhida: **squat/aranha** (corpo compacto, CG baixo, base larga). Decisão documentada em `docs/trade-studies/geometria.md`.

## Project Structure

```
Lander/
├── AGENTS.md                # Este arquivo
├── README.md                # Visão geral para humanos
├── docs/                    # Documentação técnica
│   ├── mission-profile.md
│   ├── system-requirements.md
│   └── trade-studies/       # Análises de decisão (geometria, propulsão, etc.)
├── firmware/                # Código do flight computer
│   ├── flight-computer/     # Firmware principal (C/C++ para MCU)
│   ├── ground-station/      # Estação solo (telemetria)
│   └── tests/               # Testes de firmware
├── simulation/              # Modelos de simulação
│   ├── rocketpy/            # Scripts RocketPy (Python)
│   ├── openrocket/          # Projetos OpenRocket
│   └── 6dof/                # Simulação 6-DOF custom
├── cad/                     # Modelos CAD
│   ├── airframe/            # Corpo central
│   ├── tvc-mount/           # Thrust Vector Control
│   ├── landing-legs/        # Pernas de pouso
│   └── exports/             # STL, STEP para impressão
├── electronics/             # Hardware eletrônico
│   ├── schematics/          # Esquemas (KiCad/Altium)
│   ├── pcb/                 # Layouts de PCB
│   └── bom/                 # Bill of Materials
├── tests/                   # Relatórios e dados de testes físicos
│   ├── static-fire/
│   ├── tvc-bench/
│   ├── tethered-hover/
│   └── drop-tests/
└── media/                   # Fotos e vídeos
```

## Hardware Platform

- **MCU:** TBD (candidatos: ESP32, STM32, Teensy 4.x)
- **Sensores:** IMU 9-DOF, barômetro, GPS
- **Atuação:** Servos para TVC (2 DOF), igniter, válvula (se cold gas)
- **Comunicação:** Telemetria RF (LoRa ou similar)
- **Fabricação:** Ender 3 com Klipper (LaRA), materiais: Nylon-CF, PC, TPU, PETG

## Firmware

Linguagem: **C/C++** (Arduino/PlatformIO ou bare-metal STM32).

### Arquitetura esperada
- State machine de voo: `ARMED → LIFTOFF → ASCENT → APOGEE → DESCENT → LANDING`
- Fusão sensorial: Kalman Filter (EKF) para estado do veículo
- Controle: PID ou MPC para atitude via TVC
- Loop de controle: >100 Hz

### Critical Don'ts (firmware)
- NUNCA use `malloc`/`free` após inicialização
- NUNCA use `printf`/`Serial.print` em loops de controle críticos
- NUNCA acesse periféricos diretamente — use HAL/drivers próprios
- NUNCA use float point em ISRs
- NUNCA bloqueie o loop principal — use state machine não-bloqueante

## Simulation (Python)

- Bibliotecas: `rocketpy`, `numpy`, `matplotlib`, `scipy`
- Ambiente virtual: `python -m venv .venv && source .venv/bin/activate`
- Dependências: `pip install -r simulation/requirements.txt`
- Scripts em `simulation/rocketpy/` devem ser executáveis standalone

## CAD

- **Software:** Onshape (online, gratuito para estudantes)
- **Export:** STL para impressão, STEP para intercâmbio
- **Arquivo fonte:** Manter .f3z ou link do Onshape em `cad/` quando possível
- **Naming:** `componente_material_vN.stl` (ex: `body-nylon-cf_v03.stl`)

## Code Style

### Firmware (C/C++)
- Prefixo de módulo: `tvc_`, `gnc_`, `avionics_`, `landing_`
- Constantes: `UPPER_SNAKE_CASE`
- Funções: `lower_snake_case`
- Structs: `PascalCase`
- Comentários em inglês
- Headers com include guards ou `#pragma once`

### Simulation (Python)
- Seguir PEP 8
- Type hints em funções públicas
- Docstrings NumPy style
- Imports agrupados: stdlib → third-party → local

## Testing

### Firmware
- Testes de unidade em `firmware/tests/` (se aplicável)
- Bench tests antes de integração: TVC isolado, sensores isolados
- Validar sempre em hardware — simulação não substitui teste físico

### Simulation
- Scripts devem rodar sem erro: `python simulation/rocketpy/<script>.py`
- Verificar com `python -m pytest simulation/tests/` (quando existir)

## Commit & PR Guidelines

- **Formato:** `[subsystem] descrição breve`
  - Exemplos: `[tvc] add servo calibration routine`, `[sim] fix drag coefficient`, `[docs] add propulsion trade study`
- **Subsistemas:** `tvc`, `gnc`, `avionics`, `landing`, `sim`, `cad`, `electronics`, `docs`, `test`
- **Commits atômicos:** uma mudança lógica por commit
- **NÃO committar:** arquivos STL grandes (>50 MB), segredos, credenciais, `.env`
- Branches: `feature/<subsystem>-<descricao>`, `fix/<descricao>`

## Safety & Critical Constraints

- Este é um projeto com **motor foguete** — segurança é não-negociável
- Nunca sugerir código que faça ignição ou armazenar propulsor sem sistema de segurança
- Testes de fogo estático e hover amarrado ANTES de voo livre
- Sistema de abort com paraquedas é obrigatório (backup)
- Seguir regras da LASC (LGR) sempre

## Important Notes for AI

- O projeto está em **Fase 0** (conceito) — muito código ainda não existe
- Quando criar novo firmware, use a estrutura de pastas proposta acima
- Não assumir MCU específico até que a decisão seja documentada
- Quando em dúvida sobre segurança, pergunte ao invés de assumir
- Documentação em **português** (equipe brasileira), mas código em **inglês**
- Referências externas estão no README.md — consulte antes de sugerir libs/abordagens

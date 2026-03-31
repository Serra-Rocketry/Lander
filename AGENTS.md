# AGENTS.md — Serra Lander

Guia geral para AI coding assistants que trabalham neste repositório.

## Project Overview

**Serra Lander** é um veículo lander VTOL para o Lander Challenge da LASC 2026 (setembro/2026, Iacanga-SP). Projeto open-source do Serra Rocketry / LaRA-IPRJ/UERJ.

Missão: decolar verticalmente, atingir 50 m AGL, descer controlado e pousar propulsivamente sem paraquedas.

Configuração escolhida: **squat/aranha** (corpo compacto, CG baixo, base larga). Decisão documentada em `docs/trade-studies/geometria.md`.

## Project Structure

```
Lander/
├── AGENTS.md                # Este arquivo (geral)
├── README.md                # Visão geral para humanos
├── docs/                    # Documentação técnica
│   └── AGENTS.md            # Convenções de documentação e segurança
├── firmware/                # Código do flight computer
│   ├── AGENTS.md            # Convenções de firmware (C/C++)
│   ├── flight-computer/     # Firmware principal
│   ├── ground-station/      # Estação solo (telemetria)
│   └── tests/               # Testes de firmware
├── simulation/              # Modelos de simulação
│   ├── AGENTS.md            # Convenções de simulação (Python)
│   ├── rocketpy/            # Scripts RocketPy
│   ├── openrocket/          # Projetos OpenRocket
│   └── 6dof/                # Simulação 6-DOF custom
├── cad/                     # Modelos CAD
│   ├── AGENTS.md            # Convenções de CAD
│   ├── airframe/            # Corpo central
│   ├── tvc-mount/           # Thrust Vector Control
│   ├── landing-legs/        # Pernas de pouso
│   └── exports/             # STL, STEP para impressão
├── electronics/             # Hardware eletrônico
│   ├── AGENTS.md            # Convenções de eletrônicos
│   ├── schematics/          # Esquemas (KiCad/Altium)
│   ├── pcb/                 # Layouts de PCB
│   └── bom/                 # Bill of Materials
├── tests/                   # Relatórios e dados de testes físicos
│   ├── AGENTS.md            # Procedimentos de teste e segurança
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

## Commit & PR Guidelines

- **Formato:** `[subsystem] descrição breve`
  - Exemplos: `[tvc] add servo calibration routine`, `[sim] fix drag coefficient`, `[docs] add propulsion trade study`
- **Subsistemas:** `tvc`, `gnc`, `avionics`, `landing`, `sim`, `cad`, `electronics`, `docs`, `test`
- **Commits atômicos:** uma mudança lógica por commit
- **NÃO committar:** arquivos STL grandes (>50 MB), segredos, credenciais, `.env`
- Branches: `feature/<subsystem>-<descricao>`, `fix/<descricao>`

## Important Notes for AI

- O projeto está em **Fase 0** (conceito) — muito código ainda não existe
- Para convenções específicas de cada subsistema, leia o AGENTS.md da pasta correspondente
- Não assumir MCU específico até que a decisão seja documentada
- Quando em dúvida sobre segurança, pergunte ao invés de assumir
- Documentação em **português** (equipe brasileira), mas código em **inglês**
- Referências externas estão no README.md — consulte antes de sugerir libs/abordagens

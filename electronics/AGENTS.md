# AGENTS.md — Electronics

Convenções para hardware eletrônico do Serra Lander.

## Ferramentas

- **ECAD:** KiCad ou Altium (TBD)
- **Formato de esquemas:** Nativo do EDA + PDF export

## Hardware Platform (detalhes)

- **MCU:** TBD (candidatos: ESP32, STM32, Teensy 4.x)
- **Sensores:** IMU 9-DOF, barômetro, GPS
- **Atuação:** Servos para TVC (2 DOF), igniter, válvula (se cold gas)
- **Comunicação:** Telemetria RF (LoRa ou similar)
- **Alimentação:** TBD (LiPo, reguladores, proteções)

## Naming Convention

- Esquemas: `subsystem_version.kicad_sch` (ex: `avionics_v01.kicad_sch`)
- PCB: `subsystem_version.kicad_pcb`
- BOM: `bom_subsystem.csv`

## Pasta BOM

- Bill of Materials em CSV
- Colunas: Part, Value, Footprint, Qty, Supplier, MPN

---

> **Para o AI assistant:** Ao trabalhar neste subsistema, sugira updates a este AGENTS.md quando:
> - MCU e componentes forem selecionados
> - Novas convenções de nomenclatura forem estabelecidas
> - Novos padrões de esquema/PCB forem adotados

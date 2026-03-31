# Requisitos de Sistema — Serra Lander

## Requisitos funcionais

| ID | Requisito | Prioridade | Status |
|----|-----------|------------|--------|
| FR-01 | Decolar verticalmente sem auxílio externo | Must | TBD |
| FR-02 | Alcançar 50 m AGL (± tolerância TBD) | Must | TBD |
| FR-03 | Descer controlado sem paraquedas | Must | TBD |
| FR-04 | Pousar propulsivamente | Must | TBD |
| FR-05 | Transmitir telemetria em tempo real | Should | TBD |
| FR-06 | Log completo de dados de voo | Must | TBD |
| FR-07 | Sistema de abort por paraquedas | Must | TBD |

## Requisitos não-funcionais

| ID | Requisito | Valor alvo |
|----|-----------|------------|
| NFR-01 | Massa total (dry) | < 5 kg |
| NFR-02 | Loop de controle | ≥ 100 Hz |
| NFR-03 | Latência de telemetria | < 200 ms |
| NFR-04 | Autonomia de bateria | > 5 min (missão + margem) |
| NFR-05 | Altitude máxima de operação | 60 m AGL (com margem) |

## Requisitos de segurança

| ID | Requisito | Notas |
|----|-----------|-------|
| SR-01 | Kill switch remoto | Desligamento por RF |
| SR-02 | Abort automático por perda de controle | Deploy paraquedas |
| SR-03 | Interlock de ignição | Físico + lógico |
| SR-04 | Exclusion zone durante testes | 50 m mínimo (LASC) |
| SR-05 | Verificação pré-voo | Checklist obrigatório |

## Status

- [ ] Definir requisitos finais com base no LCSM
- [ ] Traceability matrix (requisito → código/teste)
- [ ] Revisão pela equipe

# Perfil de Missão — Serra Lander

## Visão geral

O Serra Lander deve executar uma missão VTOL (Vertical Takeoff and Vertical Landing) com o seguinte perfil:

```
T=0s        Ignição → Decolagem vertical
T=~3s       Apogeu alvo: 50 m AGL
T=~3-5s     Transição para descida controlada
T=~8-10s    Desaceleração e alinhamento para pouso
T=~10-12s   Touchdown propulsivo
```

## Requisitos de missão

| Parâmetro | Valor | Notas |
|-----------|-------|-------|
| Apogeu alvo | 50 m AGL | ±5 m tolerância (estimado LCSM) |
| Decolagem | Vertical autônoma | Sem guia, sem torre |
| Descida | Controlada, sem paraquedas | TVC + throttle |
| Pouso | Propulsivo | Velocidade de touchdown < 2 m/s |
| Telemetria | Completa | Log onboard + RF em tempo real |

## Estados de voo

```
IDLE → ARMED → LIFTOFF → ASCENT → APOGEE → DESCENT → FLARE → TOUCHDOWN → SAFE
```

- **IDLE:** Solo, desarmado
- **ARMED:** Sistema armado, pronto para ignição
- **LIFTOFF:** Motor ativo, decolagem
- **ASCENT:** Subida vertical
- **APOGEE:** Altitude máxima atingida
- **DESCENT:** Descida controlada (motor ativo ou coasting + reignição)
- **FLARE:** Desaceleração final antes do pouso
- **TOUCHDOWN:** Contato com o solo
- **SAFE:** Motor desligado, sistema em estado seguro

## Contingências

| Cenário | Ação |
|---------|------|
| Apogeu muito alto (>60m) | Desligar motor mais cedo, descer mais tempo |
| Apogeu muito baixo (<40m) | Não há tempo para correção — pousar |
| Perda de controle de atitude | Abort → paraquedas |
| Falha de sensor primário | Redundância (fallback para sensor secundário) |
| Falha de comunicação | Autonomia completa — seguir missão |

## Status

- [ ] Escrever missão profile detalhado (este documento)
- [ ] Definir abort criteria com base no LCSM (quando publicado)
- [ ] Validar perfil com simulação RocketPy

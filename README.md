# Serra Lander

**Veículo lander propulsivo para o Lander Challenge da LASC 2026**

Serra Rocketry | LaRA — Laboratório de Robótica e Automação | IPRJ/UERJ

> Foguete VTOL (Vertical Takeoff and Vertical Landing) com apogeu alvo de 50 m e pouso autônomo propulsivo. Projeto open-source com estrutura majoritariamente impressa em 3D utilizando materiais de engenharia (TPU, PC, Nylon-CF).

---

## Sobre o projeto

Este repositório concentra todo o desenvolvimento do veículo lander da equipe Serra Rocketry para o **Lander Challenge** da [LASC 2026](https://www.lasc.space/) (7th Latin American Space Challenge), que acontecerá em setembro de 2026 no Sugarcane Launch Range, em Iacanga (SP).

O Lander Challenge é uma categoria nova na LASC 2026, somando-se ao Rocket Challenge e ao Satellite Challenge. O desafio consiste em projetar e voar um veículo que decola verticalmente, atinge um apogeu alvo (no nosso caso, 50 m) e retorna ao solo de forma controlada com pouso propulsivo — sem paraquedas, sem amarras.

### Objetivos da missão

- Decolagem vertical autônoma
- Apogeu alvo de 50 m AGL
- Transição controlada para descida
- Pouso propulsivo suave e autônomo
- Registro completo de telemetria de voo

## Status atual

🟡 **Fase 0 — Pesquisa e definição de conceito**

O manual específico do Lander Challenge da LASC (LCSM) ainda não foi publicado (data TBD). Estamos na fase de pesquisa de conceito, definição de arquitetura e prototipagem de subsistemas.

### Documentação LASC 2026 disponível

| Documento | Status |
|-----------|--------|
| [LASC General Rules (LGR)](https://drive.google.com/file/d/1fDEQsoQ36Da3YmeCA9Bnu1X3AhxRkD4j/view) | Ed. 1 Rev. 01 (17/mar/2026) |
| [Event Guidance & Milestones (EGM)](https://drive.google.com/file/d/1Ig1qGCeXguCPvUUHcCH5E8kHcYAcKrfI/view) | Ed. 2 Rev. 01 (17/mar/2026) |
| Lander Challenge Standard Manual (LCSM) | ⏳ TBD |
| [Entry Application](https://docs.google.com/forms/d/e/1FAIpQLSdEClv_B29Hdg4H2M4UNM0m_7ivVkU3rR1Mm0KDWdxA8x2GRw/viewform) | Aberta |

## Arquitetura do veículo

### Visão geral dos subsistemas

```
┌─────────────────────────────────┐
│         SERRA LANDER            │
├─────────────┬───────────────────┤
│ Estrutura   │ Airframe impresso │
│             │ em 3D (TPU/PC/    │
│             │ Nylon-CF) + metal │
│             │ na zona quente    │
├─────────────┼───────────────────┤
│ Propulsão   │ Motor(es) com     │
│             │ capacidade de     │
│             │ throttle ou       │
│             │ controle de       │
│             │ empuxo            │
├─────────────┼───────────────────┤
│ GNC         │ Guiagem,          │
│ (Guidance,  │ Navegação e       │
│ Navigation  │ Controle:         │
│ & Control)  │ IMU + baro +      │
│             │ GPS + PID/MPC     │
├─────────────┼───────────────────┤
│ TVC         │ Thrust Vector     │
│             │ Control: gimbal   │
│             │ do motor via      │
│             │ servos            │
├─────────────┼───────────────────┤
│ Aviônica    │ Flight computer   │
│             │ + telemetria +    │
│             │ data logging      │
├─────────────┼───────────────────┤
│ Pouso       │ Landing legs com  │
│             │ deploy mecânico   │
│             │ e absorção de     │
│             │ impacto           │
└─────────────┴───────────────────┘
```

## Pesquisa de referência

### Projetos de estudantes e makers (open-source)

| Projeto | Descrição | Link |
|---------|-----------|------|
| **BPS.space (Joe Barnard)** | Referência #1 mundial em pouso propulsivo com motor sólido. TVC impresso em 3D (PLA), depois migrado para alumínio. Flight computer AVA. Levou ~7 anos até o primeiro pouso bem-sucedido com o Scout-F. | [bps.space](https://bps.space) |
| **rocket-vtol (Jason Chen)** | Sistema VTOL para foguete híbrido com visão computacional, RL para controle, RCS e TVC. Python 3.7, bem documentado. | [github](https://github.com/JayChen35/rocket-vtol) |
| **Autonomous-Landing-of-Model-Rocket** | Projeto acadêmico com TVC via gimbal, PID + Kalman Filter, flight computer, peças 3D impressas, análise FEM e CFD. | [github](https://github.com/Landing-Rockets/Autonomous-Landing-of-Model-Rocket) |
| **Collegiate Propulsive Lander Challenge (CPLC)** | Competição com 5 milestones: TVC hotfire, throttleable engine, tethered hover, drop landing e hop (>150 ft / ~46 m com 30 lb payload). Várias universidades participam (Purdue, Cal Poly, Texas A&M, Stanford). | [landerchallenge.space](https://landerchallenge.space) |
| **LAD-5 (3D-Printed Supersonic Rocket)** | Airframe inteiramente impresso em Nylon PA-12 com layup de fibra de carbono/vidro sobre o substrato impresso. Voou supersônico. | [site](https://carbonheliumnitrogen.github.io/lad.html) |
| **Astrorizzicist** | Foguete ~95% impresso em 3D (PLA), certificação L2 NAR, STLs e STEP publicados. | [printables](https://www.printables.com/model/824879) |
| **TTS Aerospace** | Também conseguiu pouso propulsivo de model rocket, alternativa ao BPS.space | YouTube |
| **OpenRocket** | Simulador open-source 6-DOF para foguetes. Essencial para projeto de trajetória. | [openrocket.info](https://openrocket.info) |
| **RocketPy** | Simulador de trajetória em Python, usado oficialmente pela LASC. | [github](https://github.com/RocketPy-Team/RocketPy) |

### Lições aprendidas dos projetos de referência

**Do BPS.space (Joe Barnard):**
- Motores sólidos não permitem throttle direto, mas o empuxo efetivo pode ser controlado oscilando o TVC lateralmente ou usando "pincers" cerâmicas que bloqueiam parte da saída
- O timing de ignição do motor de descida é crítico e precisa de repetibilidade no empuxo
- Landing legs de fibra de carbono com deploy por nichrome + elástico. Precisam absorver impacto sem bouncing
- Migrou TVC de PLA impresso para alumínio usinado para eliminar folga e flex
- Flight simulation em MATLAB/Simulink é fundamental antes de qualquer voo

**Do CPLC:**
- Abordagem por milestones é inteligente: primeiro provar throttle, depois hover amarrado, depois hop. Não tentar tudo de uma vez
- A maioria dos times usa propulsão líquida ou híbrida (etanol + N2O, IPA + N2O) para ter throttle real
- Empuxo típico: >500 lbf (~2200 N) para os projetos do CPLC, mas para 50 m com veículo leve, pode ser muito menos

## Estrutura impressa em 3D — Materiais e viabilidade

### Filosofia: materiais de guerra de robôs aplicados a foguetaria

A ideia é usar a expertise da comunidade de combat robotics em materiais de alta resistência ao impacto, adaptando para as demandas de um lander: leveza, resistência ao choque do pouso e capacidade de suportar vibração e cargas aerodinâmicas. As Ender 3 do LaRA com Klipper são a plataforma de fabricação.

### Mapa de materiais por zona do veículo

```
        ┌───────────┐
        │  NOSE     │  ← PLA/PETG (baixo estresse, só aerodinâmica)
        │  CONE     │
        ├───────────┤
        │           │
        │ AVIÔNICA  │  ← PETG ou Nylon (suportes internos, sleds)
        │  BAY      │
        │           │
        ├───────────┤
        │           │
        │ AIRFRAME  │  ← Nylon-CF ou PC (estrutura principal)
        │ CENTRAL   │     ou Nylon PA-12 + layup de fibra
        │           │
        ├───────────┤
        │           │
        │  TVC      │  ← Nylon-CF ou alumínio (alta carga, precisão)
        │  MOUNT    │
        │           │
        ├───────────┤
        │           │
        │ MOTOR     │  ← METAL (alumínio, aço) — zona quente
        │ SECTION   │     NÃO IMPRIMIR
        │           │
        ├───┬───┬───┤
       /    |   |    \
      / LANDING LEGS  \  ← TPU (absorção de impacto)
     /   (deploy)      \    + hastes de carbono (rigidez)
```

### Materiais detalhados

#### TPU (Poliuretano Termoplástico) — Landing legs, absorvedores de choque

- **Ponto forte:** Absorção de impacto excepcional, não quebra, não lasca. Resistente a abrasão. Ideal para componentes que precisam flexionar no pouso sem falhar.
- **Uso em combate:** Rodas, armaduras flexíveis, bumpers.
- **Uso no lander:** Pés das landing legs, bumpers de proteção, dampers de vibração, grommets de montagem.
- **Grades recomendados:** TPU 95A (mais rígido, mais fácil de imprimir) ou 85A (mais flexível, melhor absorção).
- **Desafios na impressão:** Velocidade lenta obrigatória (~20-30 mm/s), retraction mínima ou zero, extrusora direta preferível (Bowden é possível com configuração cuidadosa no Klipper). Klipper ajuda com pressure advance calibrado.
- **Temp. impressão:** ~220-240°C nozzle, 50-60°C bed.
- **Zona térmica:** Não usar perto do motor. Amolece acima de ~80°C.

#### Polycarbonato (PC / Lexan) — Estrutura principal, componentes de alta carga

- **Ponto forte:** Extremamente resistente ao impacto (é o material das paredes de arenas de combat robots). Rígido sem ser frágil. Boa resistência térmica (~140°C HDT).
- **Uso em combate:** Chassis, armaduras, paredes de arena.
- **Uso no lander:** Seções estruturais do airframe, brackets de montagem de motor, suportes da aviônica.
- **Desafios na impressão:** Requer temperaturas altas (nozzle 270-300°C, bed 110-135°C), enclosure é praticamente obrigatório para evitar warping severo. Delaminação entre camadas é o problema mais comum.
- **Dica:** PC-Max da Polymaker é uma blend formulada para ser mais fácil de imprimir. A Ender 3 com hotend all-metal e enclosure pode dar conta.
- **Zona térmica:** Pode ser usado mais perto do motor que TPU/PLA, mas ainda não na zona de exaustão direta.

#### Nylon com Fibra de Carbono (NylonX, CF-Nylon, PA-CF) — TVC mount, estrutura primária

- **Ponto forte:** A melhor relação resistência/peso para impressão 3D. Rígido, leve, resistente. O material preferido da comunidade de combat robotics para peças estruturais.
- **Uso em combate:** Chassis principais, weapon mounts, componentes de alta carga.
- **Uso no lander:** TVC mount (se não for alumínio), centering rings, estrutura do airframe, brackets de landing legs.
- **Desafios na impressão:** Exige nozzle de aço endurecido (hardened steel) pois as fibras de carbono destroem nozzles de latão. Higroscópico — precisa de dry box para armazenamento. Nozzle 250-270°C, bed 70-90°C. Enclosure recomendado.
- **Custo:** ~6x mais caro que PLA, mas para peças estruturais críticas vale muito a pena.

#### PETG — Componentes secundários, prototipagem

- **Ponto forte:** Fácil de imprimir, boa adesão entre camadas, resistente ao impacto razoável. Bom custo-benefício.
- **Uso no lander:** Prototipagem rápida, suportes internos da aviônica, carenagens não-estruturais, sleds de eletrônica.
- **Zona térmica:** Similar ao TPU, não usar perto do motor.

#### PLA — Apenas prototipagem

- **Ponto forte:** O mais fácil de imprimir, barato, bom para iteração rápida.
- **Uso no lander:** SOMENTE protótipos e mockups. Frágil demais para voo, baixa resistência térmica (~60°C).
- **NUNCA usar PLA em peças de voo estruturais.**

### O que NÃO imprimir (zona quente / motor)

- **Motor mount / motor casing:** Alumínio ou aço obrigatório. As temperaturas de exaustão de motor sólido excedem 1000°C. Nenhum termoplástico sobrevive.
- **Nozzle e região de exaustão:** Metal.
- **Thrust plate:** Alumínio, para transferir carga do motor para o airframe sem deformação.
- **Approach híbrido:** Usar insertos metálicos (heat-set inserts de latão, parafusos de alumínio) dentro de peças impressas para pontos de fixação de alta carga.

### Técnicas de reforço para peças impressas

- **Mais paredes > mais infill:** Aumentar número de perímetros é mais efetivo que aumentar infill. 4-6 paredes com 15-20% infill costuma ser melhor que 2 paredes com 80% infill.
- **Orientação de camadas:** Orientar a peça no slicer para que a direção de maior estresse seja paralela às camadas, não perpendicular (layer lines são o ponto mais fraco).
- **Annealing:** Aquecer peças impressas no forno (abaixo da temperatura de deformação) para relaxar tensões internas e melhorar adesão entre camadas. Funciona especialmente bem com PLA e Nylon.
- **Composito impresso:** Imprimir substrato em Nylon/PA-12 e fazer layup de fibra de carbono/vidro por cima. Abordagem usada no projeto LAD-5 para voar supersônico.
- **Heat-set inserts:** Usar insertos de latão para todas as fixações parafusadas. Permite montagem/desmontagem sem degradar o plástico.

## Geometrias possíveis do veículo

### Configuração 1 — Cilíndrica clássica (tipo Falcon 9 / BPS Scout)

```
    ╱╲
   ╱  ╲       Nose cone
  ╱    ╲
 ┌──────┐
 │      │     Aviônica
 │      │
 ├──────┤
 │      │     Tanques / motor
 │      │
 │ ▼▼▼▼ │     TVC mount + motor
 └┤    ├┘
  ╱╲  ╱╲     Landing legs (3 ou 4)
 ╱  ╲╱  ╲
```

- **Vantagens:** Geometria mais estudada, vasta referência (BPS.space, CPLC), fácil de simular.
- **Desvantagens:** Centro de gravidade alto, demanda controle ativo constante para estabilidade no pouso.
- **Impressão 3D:** Airframe cilíndrico pode ser impresso em seções que encaixam com couplers. Boa modularidade.

### Configuração 2 — Squat / Low-profile (tipo lunar lander)

```
     ┌──┐
     │  │     Aviônica (topo)
  ┌──┴──┴──┐
  │        │  Plataforma central
  │  MOTOR │  (motor no centro)
  └┬┬┬┬┬┬┬┘
  ╱╱╱╱╱╱╱╱   Landing legs curtas e largas
```

- **Vantagens:** CG mais baixo, naturalmente mais estável no pouso, base larga.
- **Desvantagens:** Mais arrasto aerodinâmico na subida, menos referências disponíveis.
- **Impressão 3D:** Plataforma central é perfeita para impressão 3D — geometrias complexas com cavidades internas.

### Configuração 3 — Híbrida (subida como foguete, pouso como lander)

- Sobe como foguete convencional com fins (estabilidade passiva na subida)
- No apogeu, deploya legs e transiciona para descida controlada
- Motor de descida pode ser separado do motor de subida

**Vantagens:** Separa os problemas: subida usa aerodinâmica convencional, descida usa controle ativo.

## Desafios técnicos principais

### 1. Propulsão com controle de empuxo

O maior desafio técnico. Opções:

| Abordagem | Prós | Contras |
|-----------|------|---------|
| **Motor sólido + timing** | Simples, barato, acessível | Sem controle real de empuxo, depende de repetibilidade |
| **Motor sólido + pincer/throttle mecânico** | BPS provou que funciona | Complexo mecanicamente, desgaste |
| **Motor sólido + TVC oscilante** | Reduz componente vertical do empuxo | Controle impreciso, estresse na estrutura |
| **Motor híbrido (N2O + combustível sólido)** | Throttle real, shutoff/restart possível | Mais complexo, necessita tanque de oxidante pressurizado |
| **Cold gas thruster (N2 ou CO2)** | Simples, seguro, throttle perfeito via válvula | Baixo impulso específico, tanque pesado |
| **Bipropelente (etanol + N2O)** | Throttle total, alta performance | Muito complexo, alto custo, segurança |

**Recomendação para o Serra Lander:** Começar com motor sólido + TVC para a fase de subida, e investigar cold gas ou motor sólido com timing para a descida. A longo prazo, um motor híbrido dá mais controle.

### 2. GNC (Guiagem, Navegação e Controle)

- **Sensores mínimos:** IMU 9-DOF (acelerômetro + giroscópio + magnetômetro) + barômetro + GPS
- **Fusão sensorial:** Kalman Filter (EKF) para estimar posição, velocidade e atitude
- **Controle de atitude:** PID (para começar) ou MPC (Model Predictive Control, mais robusto)
- **Plataforma:** ESP32 ou STM32 ou Teensy 4.x
- **Referência de software:** O BPS.space não disponibiliza seu flight software, mas o conceito é bem documentado na série "Landing Model Rockets" no YouTube

### 3. TVC (Thrust Vector Control)

- Gimbal mount com 2 graus de liberdade (pitch + yaw)
- Atuadores: micro servos de alta velocidade e torque
- Ângulo de deflexão: tipicamente ±5° a ±8°
- Largura de banda: >10 Hz (resposta rápida)
- BPS.space usa montagem impressa em 3D para TVC de motores de até 29 mm

### 4. Landing legs

- Precisam ser leves, com deploy confiável e absorção de impacto
- Mecanismo de deploy: mola + retenção por nichrome/rubber band (BPS) ou servo
- Material: hastes de fibra de carbono (rigidez) com pés em TPU (absorção)
- Número de pernas: 3 (mínimo, triângulo estável) ou 4 (mais estável, mais peso)
- Base da perna quando deployed deve ser > 1.5x o diâmetro do corpo para estabilidade

### 5. Segurança

- **Abort system:** Paraquedas como backup obrigatório caso o pouso falhe
- **Kill switch:** Desligamento remoto do motor
- **Exclusion zone:** Seguir normas da LASC rigorosamente
- **Testes amarrados primeiro:** Nunca tentar voo livre sem validar hover amarrado

## Estrutura do repositório (proposta)

```
serra-lander/
├── README.md
├── LICENSE
├── docs/
│   ├── mission-profile.md
│   ├── system-requirements.md
│   ├── trade-studies/
│   └── lasc-docs/
├── cad/
│   ├── airframe/
│   ├── tvc-mount/
│   ├── landing-legs/
│   ├── avionics-bay/
│   └── exports/          # STL, STEP
├── firmware/
│   ├── flight-computer/
│   ├── ground-station/
│   └── tests/
├── simulation/
│   ├── openrocket/
│   ├── rocketpy/
│   ├── matlab-simulink/
│   └── 6dof/
├── electronics/
│   ├── schematics/
│   ├── pcb/
│   └── bom/
├── tests/
│   ├── static-fire/
│   ├── tvc-bench/
│   ├── tethered-hover/
│   └── drop-tests/
└── media/
    ├── photos/
    └── videos/
```

## Roadmap

### Fase 0 — Conceito (abril/maio 2026) ← ESTAMOS AQUI
- [ ] Pesquisa de referência e trade studies
- [ ] Definir configuração do veículo
- [ ] Definir sistema de propulsão
- [ ] Aguardar e analisar LCSM quando publicado
- [ ] Simulação preliminar de trajetória (RocketPy / OpenRocket)

### Fase 1 — Subsistemas (maio/junho 2026)
- [ ] Prototipar TVC mount impresso em 3D
- [ ] Desenvolver flight computer (hardware + firmware básico)
- [ ] Prototipar landing legs (print + teste de drop)
- [ ] Static fire do motor com TVC
- [ ] Testes de bancada dos sensores (IMU + baro + GPS)

### Fase 2 — Integração (junho/julho 2026)
- [ ] Tethered hover test
- [ ] Integração dos subsistemas
- [ ] Testes de comunicação telemetria
- [ ] Iteração no controle PID/MPC

### Fase 3 — Voo (julho/agosto 2026)
- [ ] Voo de teste com abort por paraquedas
- [ ] Tentativas de pouso propulsivo
- [ ] Documentação e progress updates para LASC

### Fase 4 — Competição (setembro 2026)
- [ ] LASC 2026 em Iacanga (SP)
- [ ] Mission report

## Recursos úteis

### Vídeos essenciais
- [Landing Model Rockets — BPS.space (série completa)](https://www.youtube.com/playlist?list=PLpjdWF5iIlbIYmMUQM9bT7YeoC86hpbKl) — Série que cobre todos os fundamentos de pouso propulsivo
- [RocketPy Training LASC](https://www.youtube.com/watch?v=nBL_1zhV2zg) — Tutorial oficial de simulação de trajetória

### Software
- [OpenRocket](https://openrocket.info/) — Simulador de foguetes 6-DOF
- [RocketPy](https://github.com/RocketPy-Team/RocketPy) — Simulação de trajetória em Python
- [Onshape](https://www.onshape.com/) — CAD gratuito para estudantes (usado pelo BPS.space)

### Documentação LASC
- [Site oficial LASC](https://www.lasc.space/)
- [Documentação 2026 LASC](https://www.lasc.space/2026-lasc/documentation)

## Equipe

**Serra Rocketry** — Projeto de extensão em foguetemodelismo do LaRA (Laboratório de Robótica e Automação), IPRJ/UERJ, Nova Friburgo, RJ.

## Licença

[A definir — sugestão: MIT ou CERN-OHL-S para hardware open-source]

---

*"O canavial não é o limite."* 🚀

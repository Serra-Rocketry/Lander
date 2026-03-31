# Estudo de geometria do veículo

Serra Lander — LASC 2026 Lander Challenge

**Status:** Decisão de conceito
**Data:** 2026-03-30
**Autor:** LaRA / Serra Rocketry

---

## Resumo executivo

Após análise de três famílias de configuração geométrica (cilíndrico alto, squat/aranha e híbrido), a configuração recomendada para o Serra Lander é a **squat/aranha**, inspirada no Apollo Lunar Module, no NASA Morpheus e no Armadillo Aerospace Pixel. Essa geometria oferece a melhor combinação de estabilidade no pouso, compatibilidade com fabricação por impressão 3D e adequação ao perfil de missão de 50 m de apogeu.

## Perfil de missão

O Serra Lander deve decolar verticalmente, atingir 50 m de altitude, transicionar para descida controlada e pousar propulsivamente sobre suas próprias pernas, sem paraquedas ou amarras. Esse perfil impõe requisitos simultâneos de estabilidade em voo, controle de atitude em baixa velocidade e absorção de impacto no pouso.

A altitude de 50 m é relativamente baixa. O veículo passará a maior parte do voo em regime subsônico e de baixa velocidade, o que significa que a eficiência aerodinâmica é secundária em relação à estabilidade e ao controle.

## Configurações analisadas

### Configuração 1 — Cilíndrico alto (tipo Falcon 9 / BPS Scout)

Formato clássico de foguete: corpo tubular esbelto com motor na base e landing legs deployáveis. É a geometria mais estudada na comunidade de model rocketry propulsivo.

**Referências:** BPS.space Scout-F (Joe Barnard), vários projetos do Collegiate Propulsive Lander Challenge (CPLC), TTS Aerospace.

**Características:**
- Corpo tubular com razão de aspecto alta (comprimento >> diâmetro)
- CG posicionado alto em relação à base
- Base de pouso estreita relativa à altura
- Boa eficiência aerodinâmica na subida
- Estabilidade passiva por fins ou ativa por TVC

**Vantagens:**
- Vasta documentação e referências disponíveis
- Aerodinâmica bem compreendida e simulável (OpenRocket, RocketPy)
- Fabricação simples do airframe (tubo cilíndrico, pode ser comercial)
- Comunidade ativa com kits e componentes

**Desvantagens:**
- CG alto torna o veículo naturalmente instável no pouso. Qualquer erro de atitude no momento do touchdown tende a tombar o veículo
- Exige controle de atitude de alta performance durante toda a fase de descida
- O Joe Barnard (BPS.space), a principal referência mundial, levou aproximadamente 7 anos de iteração para conseguir o primeiro pouso bem-sucedido com motor sólido nesta configuração
- A maioria dos projetos estudantis que tentam essa configuração falham repetidamente nos primeiros anos
- Landing legs longas e finas são vulneráveis a bouncing no pouso

**Avaliação para o Serra Lander:** Risco alto para um primeiro projeto de lander. O desafio de controle é significativamente maior do que nas outras configurações. Não recomendada.

### Configuração 2 — Squat / Aranha (tipo Apollo LM / NASA Morpheus)

Corpo compacto e largo, posicionado próximo ao solo, com pernas estruturais que criam uma base de apoio muito maior que o corpo. O motor fica no centro inferior do corpo, com as pernas se estendendo radialmente.

**Referências:** Apollo Lunar Module (NASA), Projeto Morpheus (NASA), Armadillo Aerospace Pixel/Mod (vencedor do Lunar Lander X-Prize Level 2), Masten Space Systems Xombie/Xoie.

**Características:**
- Corpo compacto com razão de aspecto baixa (largura próxima do comprimento)
- CG posicionado baixo em relação ao centro de empuxo
- Base de pouso larga (tipicamente 2x a 3x o diâmetro do corpo)
- Pernas estruturais com articulações e pés largos
- Maior arrasto aerodinâmico na subida

**Vantagens:**
- Naturalmente estável no pouso devido ao CG baixo e à base larga
- Margem de erro muito maior para atitude no momento do touchdown
- Resistente a vento lateral e a assimetrias de empuxo
- Geometria ideal para impressão 3D: corpo central compacto com cavidades internas projetáveis para aviônica, tanques e motor
- O NASA Morpheus demonstrou hops repetidos e confiáveis com essa geometria, atingindo altitudes superiores a 50 m
- O Armadillo Aerospace Pixel voou acima de 50 m e pousou com sucesso repetidamente usando essa configuração, vencendo o Northrop Grumman Lunar Lander X-Prize (Level 2, que exigia voo acima de 50 m)

**Desvantagens:**
- Mais arrasto na fase de subida (porém irrelevante para 50 m de apogeu a baixa velocidade)
- Menos referências na comunidade de model rocketry estudantil (a maioria dos projetos estudantis opta pela configuração cilíndrica)
- Pernas mais complexas mecanicamente (articulações, struts secundários)
- Simulação aerodinâmica menos direta que um cilindro (mas simulável via CFD ou testes)

**Avaliação para o Serra Lander:** Configuração recomendada. A estabilidade intrínseca compensa amplamente o arrasto adicional, que é irrelevante a 50 m. A geometria favorece a fabricação por impressão 3D e oferece a melhor probabilidade de pouso bem-sucedido no primeiro ano do projeto.

### Configuração 3 — Híbrida (foguete na subida, lander na descida)

Corpo intermediário com fins passivas para estabilidade aerodinâmica na subida e landing legs deployáveis para o pouso. O veículo sobe como um foguete convencional e pousa como um lander.

**Referências:** Conceito acadêmico, sem implementações de referência consolidadas em escala estudantil.

**Características:**
- Corpo semi-esbelto com fins na subida
- Landing legs deployáveis na descida
- Motor possivelmente dual (subida vs descida) ou único com TVC
- Transição de modo no apogeu

**Vantagens:**
- Separa os problemas: subida usa princípios aerodinâmicos consolidados, descida usa controle ativo
- Aerodinâmica razoável na subida
- Estabilidade de pouso intermediária

**Desvantagens:**
- Complexidade de dois "modos" de voo com transição
- Poucas referências implementadas
- Não é claramente superior a nenhuma das outras em qualquer critério individual
- Risco de ser "meio-termo em tudo, excelente em nada"

**Avaliação para o Serra Lander:** Opção viável, mas a complexidade adicional da transição de modo não se justifica dado que a subida a 50 m não demanda otimização aerodinâmica significativa.

## Tabela comparativa

| Critério | Cilíndrico alto | Squat / aranha | Híbrido |
|----------|:-:|:-:|:-:|
| Estabilidade no pouso | Baixa | **Alta** | Média |
| Compatibilidade com impressão 3D | Média | **Alta** | Média |
| Complexidade mecânica | Média | Alta | Alta |
| Referências disponíveis | **Muitas** | Algumas | Poucas |
| Eficiência aerodinâmica | **Boa** | Baixa | Boa |
| Relevância da aerodinâmica p/ 50 m | Baixa | Baixa | Baixa |
| Risco de falha no pouso | Alto | **Baixo** | Médio |
| Facilidade de iteração | Média | **Alta** | Baixa |

## Decisão: Configuração 2 — Squat / Aranha

### Racional

1. **A missão é pousar, não voar alto.** A 50 m de altitude e baixa velocidade, a eficiência aerodinâmica é irrelevante. O fator dominante de sucesso é a estabilidade e o controle na fase de descida e pouso. A geometria squat maximiza exatamente isso.

2. **O CG baixo é um multiplicador de segurança.** Com o corpo compacto perto do solo e as pernas largas, o veículo tolera erros de atitude muito maiores sem tombar. Isso é crítico para um primeiro projeto, onde o sistema de GNC ainda está sendo amadurecido.

3. **Precedentes comprovados para a missão exata.** O Armadillo Aerospace Pixel demonstrou voo acima de 50 m com pouso controlado repetido usando essa geometria. O NASA Morpheus fez o mesmo em escala maior. Esses veículos validaram que a configuração squat funciona para exatamente esse perfil de missão.

4. **Impressão 3D como vantagem estrutural.** O corpo compacto central é ideal para as Ender 3 do LaRA: seções menores que cabem no volume de impressão, geometrias internas complexas (cavidades para aviônica, canais para fiação, pontos de montagem para motor e tanques), e modularidade por encaixe. Diferente do cilindro longo que precisa de junções entre seções, o squat pode ser impresso em poucas peças robustas.

5. **Redução de risco no cronograma.** A LASC 2026 é em setembro. Com ~6 meses de desenvolvimento, não é realista amadurecer um sistema de GNC sofisticado o suficiente para estabilizar um cilindro alto em descida. A geometria squat compra margem para o controle ser "bom o suficiente" em vez de "perfeito".

### Conceito geométrico preliminar

```
          Vista lateral                    Vista superior

         ┌────────┐
         │ avionics│                      perna 3
         │  bay   │                         │
    ┌────┴────────┴────┐              perna 2─┼─perna 1
    │                  │                      │
    │   corpo central  │                   perna 4
    │                  │
    │   ┌──────────┐   │            (config. 4 pernas, 90°)
    │   │  motor   │   │
    └───┴──┬──┬──┬─┴───┘
      ╱    │▼▼│    ╲
     ╱     └──┘     ╲
    ╱    (exaustão)   ╲
   ╱                   ╲
  ◯─────────────────────◯
  pé                    pé
  (TPU)                 (TPU)
```

**Dimensões estimadas (sujeitas a refinamento):**
- Corpo central: ~200 mm de diâmetro, ~150 mm de altura
- Base das pernas deployed: ~500-600 mm de diâmetro
- Pernas: 4 unidades a 90°, hastes de fibra de carbono com articulações impressas em Nylon-CF
- Pés: TPU 95A, geometria côncava para aderência
- Massa estimada: 2-5 kg (dependendo do sistema de propulsão)

### Elementos de estabilidade passiva

Mesmo na configuração squat, é possível adicionar elementos de estabilidade aerodinâmica para a fase de subida sem comprometer o design:

- **Aletas baixas no corpo central:** Pequenas fins fixas na parte inferior do corpo que atuam como estabilizadores na subida. São curtas o suficiente para não atrapalhar o pouso e podem ser impressas integralmente ao corpo
- **Pernas como aerofreios na descida:** As pernas, quando deployed, aumentam o arrasto do veículo na descida, reduzindo a velocidade terminal. Podem ser dimensionadas para funcionar como superfícies de arrasto controlado
- **Webbing entre pernas:** Membranas leves (tecido ou TPU fino) entre as pernas que aumentam o arrasto na descida sem adicionar massa significativa

### Materiais por componente

| Componente | Material | Justificativa |
|-----------|----------|---------------|
| Corpo central (shell) | Nylon-CF ou PC | Alta rigidez, resistência ao impacto, boa relação peso/resistência |
| Corpo central (internos) | PETG | Suportes de aviônica, sleds, divisórias internas |
| Articulações das pernas | Nylon-CF | Carga estrutural alta, precisão dimensional |
| Hastes das pernas | Fibra de carbono (tubo comercial) | Rigidez máxima com peso mínimo |
| Pés das pernas | TPU 95A | Absorção de impacto, aderência ao solo |
| Struts secundários | Fibra de carbono ou alumínio | Rigidez lateral |
| Motor mount / thrust plate | Alumínio | Resistência térmica, transferência de carga do motor |
| Nose cone / cap superior | PLA ou PETG | Componente não-estrutural, só aerodinâmica leve |

## Próximos passos

1. **Modelagem CAD preliminar** do corpo central com cavidades internas para aviônica e motor
2. **Simulação de trajetória** (RocketPy) para validar que o perfil de arrasto permite atingir 50 m com os motores candidatos
3. **Prototipagem das pernas** — imprimir articulações em Nylon-CF, montar com tubos de carbono, testar deploy e drop test
4. **Análise estrutural** (FEM simplificada) do corpo central sob cargas de pouso

## Referências

- BPS.space — Landing Model Rockets series (YouTube): https://www.youtube.com/c/BPSspace
- NASA Morpheus Project: https://www.nasa.gov/mission_pages/morpheus/main/
- Armadillo Aerospace Pixel — Lunar Lander Challenge: https://en.wikipedia.org/wiki/Lunar_Lander_Challenge
- Masten Space Systems Xombie/Xoie: veículos VTVL squat com hops repetidos
- Collegiate Propulsive Lander Challenge (CPLC): https://landerchallenge.space/
- RobotCombatWiki — 3D Printing materials: https://robotcombatwiki.com/wiki/3D_Printing
- MatterHackers — Combat robotics filaments: https://www.matterhackers.com/articles/5-materials-that-are-perfect-for-3d-printing-combat-robots
- LAD-5 3D-Printed Supersonic Rocket (Nylon PA-12 + composite layup): https://carbonheliumnitrogen.github.io/lad.html

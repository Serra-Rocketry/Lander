# AGENTS.md — Tests

Convenções e procedimentos de teste do Serra Lander.

## Safety First

- **Testes físicos envolvem motor foguete** — seguir protocolos de segurança rigorosamente
- Sempre ter área de exclusão (50m mínimo, conforme LASC)
- Kill switch remoto obrigatório
- Checklist pré-teste obrigatório

## Tipos de Teste

### Static Fire
- Validação de motor e ignição
- Medição de empuxo e repetibilidade
- Pasta: `tests/static-fire/`

### TVC Bench
- Validação do controle de vetor de empuxo em bancada
- Teste de servos, deflexão e resposta
- Pasta: `tests/tvc-bench/`

### Tethered Hover
- Hover amarrado antes de voo livre
- Validação de GNC e controle de atitude
- Pasta: `tests/tethered-hover/`

### Drop Tests
- Validação de landing legs e absorção de impacto
- Pasta: `tests/drop-tests/`

## Documentação de Testes

- Cada teste deve ter relatório em Markdown
- Incluir: data, condições, resultados, fotos/vídeos (em `media/`)
- Nomenclatura: `YYYY-MM-DD_teste-tipo.md`

---

> **Para o AI assistant:** Ao trabalhar neste subsistema, sugira updates a este AGENTS.md quando:
> - Novos procedimentos de teste forem definidos
> - Novas regras de segurança forem identificadas
> - Novos tipos de teste forem criados

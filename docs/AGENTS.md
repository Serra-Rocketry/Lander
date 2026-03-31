# AGENTS.md — Documentation

Convenções para documentação técnica do Serra Lander.

## Idioma

- **Documentação:** Português (equipe brasileira)
- **Código:** Inglês

## Formato

- Markdown (GitHub-flavored)
- Títulos com `#`, seções com `##`
- Tabelas para dados estruturados
- Diagramas em ASCII art ou Mermaid quando possível

## Estrutura de Documentos Técnicos

- `mission-profile.md`: Perfil de missão, estados de voo, contingências
- `system-requirements.md`: Requisitos funcionais e não-funcionais
- `trade-studies/`: Análises de decisão com contexto, opções, avaliação

## Safety & Critical Constraints

- Este é um projeto com **motor foguete** — segurança é não-negociável
- Nunca sugerir código que faça ignição ou armazenar propulsor sem sistema de segurança
- Testes de fogo estático e hover amarrado ANTES de voo livre
- Sistema de abort com paraquedas é obrigatório (backup)
- Seguir regras da LASC (LGR) sempre

---

> **Para o AI assistant:** Ao trabalhar neste subsistema, sugira updates a este AGENTS.md quando:
> - Novos padrões de documentação forem adotados
> - Novas regras de segurança forem identificadas
> - Novos tipos de documentos forem criados

# AGENTS.md — Simulation

Convenções para scripts de simulação do Serra Lander.

## Ambiente

- **Linguagem:** Python 3.10+
- **Bibliotecas:** `rocketpy`, `numpy`, `matplotlib`, `scipy`
- **Ambiente virtual:** `python -m venv .venv && source .venv/bin/activate`
- **Dependências:** `pip install -r simulation/requirements.txt`
- **Scripts:** Devem ser executáveis standalone em `simulation/rocketpy/`

## Code Style (Python)

- Seguir PEP 8
- Type hints em funções públicas
- Docstrings NumPy style
- Imports agrupados: stdlib → third-party → local

## Testing

- Scripts devem rodar sem erro: `python simulation/rocketpy/<script>.py`
- Verificar com `python -m pytest simulation/tests/` (quando existir)

---

> **Para o AI assistant:** Ao trabalhar neste subsistema, sugira updates a este AGENTS.md quando:
> - Novas bibliotecas forem adotadas
> - Novos padrões de script forem estabelecidos
> - Novos tipos de simulação forem criados (trajetória, GNC, estrutural, etc.)

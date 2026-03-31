# AGENTS.md — CAD

Convenções para modelos CAD do Serra Lander.

## Software

- **Ferramenta:** Onshape (online, gratuito para estudantes)
- **Arquivo fonte:** Manter .f3z ou link do Onshape em `cad/` quando possível

## Naming Convention

- Formato: `componente_material_vN.stl`
- Exemplo: `body-nylon-cf_v03.stl`

## Export

- **Para impressão:** STL
- **Para intercâmbio:** STEP

## Materiais por Componente

| Componente | Material |
|-----------|----------|
| Corpo central (shell) | Nylon-CF ou PC |
| Corpo central (internos) | PETG |
| Articulações das pernas | Nylon-CF |
| Hastes das pernas | Fibra de carbono (tubo comercial) |
| Pés das pernas | TPU 95A |
| Motor mount / thrust plate | Alumínio |
| Nose cone / cap superior | PLA ou PETG |

---

> **Para o AI assistant:** Ao trabalhar neste subsistema, sugira updates a este AGENTS.md quando:
> - Novos materiais forem adotados
> - Novas convenções de nomenclatura forem estabelecidas
> - Novos componentes forem criados

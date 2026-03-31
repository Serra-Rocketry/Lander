#!/usr/bin/env python3
"""Simulação preliminar de trajetória do Serra Lander com RocketPy.

Este script modela o perfil de missão VTOL:
1. Decolagem vertical com motor principal
2. Coast até apogeu
3. Reignição para descida controlada
4. Pouso propulsivo

Uso:
    python simulation/rocketpy/basic_trajectory.py

Dependências:
    pip install -r simulation/requirements.txt
"""

from rocketpy import Environment, SolidMotor, Rocket, Flight
from datetime import datetime


def create_environment():
    """Cria ambiente de simulação (condições em Iacanga-SP)."""
    env = Environment(
        latitude=-21.78,
        longitude=-49.15,
        elevation=450,  # Iacanga, SP ~450m ASL
    )
    env.set_date(datetime(2026, 9, 1, 12))
    env.set_atmospheric_model(type="standard_atmosphere")
    return env


def create_motor():
    """Cria modelo de motor (PLACEHOLDER — substituir com dados reais).

    TODO: Substituir por motor real quando selecionado.
    Dados aqui são placeholders para estrutura de simulação.
    """
    motor = SolidMotor(
        thrust_source="data/motors/example_motor.eng",
        burn_time=2.5,
        dry_mass=0.3,
        dry_inertia=(0.001, 0.001, 0.0001),
        nozzle_radius=0.015,
        throat_radius=0.005,
        grain_number=1,
        grain_separation=0.001,
        grain_outer_radius=0.02,
        grain_initial_inner_radius=0.01,
        grain_initial_height=0.05,
        grains_center_of_mass_position=0.025,
        coordinate_system_orientation="nozzle_to_combustion",
    )
    return motor


def create_rocket(motor):
    """Cria modelo do veículo Serra Lander (configuração squat/aranha)."""
    rocket = Rocket(
        radius=0.1,  # 200mm diâmetro
        mass=3.0,  # 3 kg dry mass (estimativa)
        inertia=(0.1, 0.1, 0.01),
        power_off_drag=0.5,
        power_on_drag=0.5,
        center_of_mass_without_motor=0.05,
        coordinate_system_orientation="tail_to_nose",
    )
    rocket.add_motor(motor, position=0)

    # TODO: Adicionar aerofreios, paraquedas, etc.
    # rocket.add_parachute(...)

    return rocket


def run_simulation():
    """Executa simulação completa."""
    env = create_environment()
    motor = create_motor()
    rocket = create_rocket(motor)

    flight = Flight(
        rocket=rocket,
        environment=env,
        rail_length=0.5,  # Lançador curto para VTOL
        inclination=90,  # Vertical
        heading=0,
    )

    # Resultados
    print(f"Apogeu: {flight.apogee - env.elevation:.1f} m AGL")
    print(f"Velocidade máxima: {flight.speed.max:.1f} m/s")
    print(f"Tempo de voo: {flight.t_final:.1f} s")

    return flight


if __name__ == "__main__":
    flight = run_simulation()
    flight.plots.trajectory_3d()

from AbstractChecker import AbstractChecker
from Character import Character
from Utils import are_allies
from Constants import ALLIES_ATTACK
from Constants import SELF_ATTACK
from Constants import VALID_RANGE

class AlliesChecker(AbstractChecker):
    def __init__(self, next_checker) -> None:
        super().__init__(next_checker)

    def execute_check(self, player_a, player_b: Character) -> None:
        if are_allies(player_a, player_b):
            if self._next_checker != None:
                self._next_checker.execute_check(player_a, player_b)
        else:
            raise Exception(ALLIES_ATTACK)

class SelfAttackChecker(AbstractChecker):
    def __init__(self, next_checker) -> None:
        super().__init__(next_checker)

    def execute_check(self, player_a, player_b: Character) -> None:
        if player_a == player_b:
            if self._next_checker != None:
                self._next_checker.execute_check(player_a, player_b)
            else:
                raise Exception(SELF_ATTACK)

class DamageChecker(AbstractChecker):
    def __init__(self, next_checker, damage) -> None:
        self._damage = damage
        super().__init__(next_checker)
    
    def execute_check(self, player_a, player_b: Character):
        if player_a.get_damage() > player_b.get_health():
            player_b.set_health(0)
            player_b.set_alive(False)
        elif player_b.get_health() - player_a.get_level() >= VALID_RANGE:
            red_damage = self._damage/2
            player_b.set_health(player_b.get_health() - red_damage)
        elif player_a.get_level() - player_b.get_level() >= VALID_RANGE:
            inc_damage = 2 * self._damage
            player_b.set_health(player_b.get_health() - inc_damage)
        else:
            player_b.set_health(player_b.get_health() - self._damage)
        if self._next_checker != None:
            self._next_checker.execute_check(player_a, player_b)
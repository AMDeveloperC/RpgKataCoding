from Character import Character
from Checkers import AlliesChecker
from Checkers import DamageChecker
from Checkers import SelfAttackChecker

class CombatRules:
    def __init__(self, player_a, player_b: Character) -> None:
        self._player_a = player_a
        self._player_b = player_b
    
    def deal_damage(self, damage: int) -> None:
        try:
            checker = AlliesChecker(SelfAttackChecker(DamageChecker(None, damage)))
            checker.execute_check(self._player_a, self._player_a)
        except TypeError:
            print("AbstractChecker should be provided")
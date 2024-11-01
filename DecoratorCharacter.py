from Character import Character
from Constants import MAX_RANGE_MELEE
from Constants import MAX_RANGE_RANGED

class AbstractDecorator(Character):
    def __init__(self, character):
        super().__init__()
        self._character = character

    def __str__(self) -> str:
        return super().__str__() + " this is the abstract decorator" + '\n'

class MeleeFighterDecorator(AbstractDecorator):
    def __init__(self, character):
        super().__init__(character)
        super().set_max_range(MAX_RANGE_MELEE)

    def __str__(self) -> str:
        return super().__str__() + " this is a melee fighters with " + str(super().get_range_max())

class RangedFighterDecorator(AbstractDecorator):
    def __init__(self, character):
        super().__init__(character)
        super().set_max_range(MAX_RANGE_RANGED)

    def __str__(self) -> str:
        return super().__str__() + " this is a melee fighters with " + str(super().get_range_max())
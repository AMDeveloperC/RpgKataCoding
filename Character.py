from typing import List

class Character:
    """
    It represents a character.

    Contains all the infos to be stored about a character.
    """
    _id = 0

    #Inizializza un'istanza dell'oggetto
    def __init__(self):
        self._max_range = 0
        self._factions = []
        self._health = 0
        self._level = 0
        self._isAlive = False
        self._damage = 0
        Character._id += 1
        self._uid = Character._id

    def get_damage(self):
        return self._damage
    
    def get_health(self):
        return self._health
    
    def get_level(self):
        return self._level

    def set_max_range(self, range: int) -> None:
        self._max_range = range
    
    def set_health(self, health: int) -> None:
        self._health = health
    
    def set_alive(self, alive: bool) -> None:
        self._isAlive = alive
    
    def set_level(self, level: int) -> None:
        self._level = level
    
    def add_faction(self, faction) -> None:
        self._factions.append(faction)
    
    def get_factions(self) -> List[int]:
        return self._factions
    
    def get_range_max(self) -> int:
        return self._max_range

    def __del__(self):
        self._factions.clear()

    def __eq__(self, other) -> bool:
        if isinstance(other, Character):
            return self._uid == other._uid
        return False
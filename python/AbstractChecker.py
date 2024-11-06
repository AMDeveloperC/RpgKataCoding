from abc import ABC, abstractmethod
from Character import Character

class AbstractChecker(ABC):
    def __init__(self, next_checker) -> None:
        if next_checker != None:
            if not isinstance(next_checker, AbstractChecker):
                raise TypeError("Next checker not set on a checker instance")
        self._next_checker = next_checker

    @abstractmethod
    def execute_check(self, a, b: Character):
        pass
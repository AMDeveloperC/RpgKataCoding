from Character import Character
from DecoratorCharacter import RangedFighterDecorator
from DecoratorCharacter import MeleeFighterDecorator
from DecoratorCharacter import AbstractDecorator
from CombatRules import CombatRules

character1 = MeleeFighterDecorator(AbstractDecorator(Character()))
character2 = RangedFighterDecorator(AbstractDecorator(Character()))

print(character1)
print(character2)

combat = CombatRules(character1, character2)
combat.deal_damage(7)
from Character import Character

def are_allies(player_a: Character, player_b: Character) -> bool:
    if len(player_a.get_factions()) == 0 and len(player_b.get_factions()) == 0:
        return True
    for faction in player_a.get_factions():
        if faction in player_b.get_factions():
            return True
    return False
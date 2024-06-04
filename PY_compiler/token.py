
class Token:
    def __init__(self, token_type, token_value=None) -> None:
        self.type = token_type
        self.value = token_value

    def __repr__(self) -> str:
        if self.value is not None:
            return f"{self.type}:{self.value}"
        return f"{self.type}"

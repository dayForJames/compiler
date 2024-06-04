
class Error:
    def __init__(self, pos_start, pos_end, error_name, detail):
        self.pos_start = pos_start
        self.pos_end = pos_end
        self.error_name = error_name
        self.detail = detail

    def error2str(self):
        return f"{self.error_name}: {self.detail} File {self.pos_start.fn}, line {self.pos_start.ln + 1}"


class IllegalCharError(Error):
    def __init__(self, pos_start, pos_end, details):
        super().__init__(pos_start, pos_end, "Illegal Character", details)

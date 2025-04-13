#include <string>
namespace Core {
struct Token {
  enum token_types {
    END,
    ID,
    LITERAL,
    IF,
    WHILE,
    FUNC,
    DEF_FUNC,
    BEG_SCOP,
    END_SCOP,
    PARENTHESIS,
    PUNCTUATION
  };
  const token_types type;
  const std::string value;
  Token(token_types type, const std::string &value)
      : type(type), value(value) {}
};
} // namespace Core

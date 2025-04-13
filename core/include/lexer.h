#include "token.h"
namespace Core {
class Lexer {
public:
  Lexer() = default;
  Lexer(const std::string &text);
  Token getNextToken();

private:
  void advance();
  void skipWhitespace();
  Token getIdentifier();
  Token getOperator();
  Token getPunctuation();
  Token getParen();
  Token literal();
  Token identifier();
  std::string readKeyword();
  // members

  std::string m_text;
  int32_t m_position;
  size_t m_size;
  char m_currentChar;
};
} // namespace Core

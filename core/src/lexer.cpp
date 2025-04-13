#include <iostream>
#include <lexer.h>

namespace Core {
Lexer::Lexer(const std::string &text)
    : m_text(text), m_position(0), m_size(text.size()) {
  m_currentChar = m_size > 0 ? m_text[m_position] : '\0';
}

Token Lexer::getNextToken() {
  while (m_currentChar != '\0') {
    if (std::isspace(m_currentChar)) {
      skipWhitespace();
      continue;
    }

    if (std::isalpha(m_currentChar)) {
      return identifier();
    }

    if (std::isdigit(m_currentChar)) {
      return literal();
    }

    if (m_currentChar == '{') {
      advance();
      return Token(Token::token_types::BEG_SCOP, "{");
    }

    if (m_currentChar == '}') {
      advance();
      return Token(Token::token_types::END_SCOP, "}");
    }

    if (m_currentChar == '(' || m_currentChar == ')') {
      std::string value(1, m_currentChar);
      advance();
      return Token(Token::token_types::PARENTHESIS, value);
    }

    if (m_currentChar == ';' || m_currentChar == ',') {
      std::string value(1, m_currentChar);
      advance();
      return Token(Token::token_types::PUNCTUATION, value);
    }

    // Handle keywords
    std::string keyword = readKeyword();
    if (keyword == "if") {
      return Token(Token::token_types::IF, keyword);
    } else if (keyword == "while") {
      return Token(Token::token_types::WHILE, keyword);
    } else if (keyword == "func") {
      return Token(Token::token_types::FUNC, keyword);
    } else if (keyword == "def") {
      return Token(Token::token_types::DEF_FUNC, keyword);
    } else if (!keyword.empty()) {
      return Token(Token::token_types::ID, keyword);
    }

    // Если символ не распознан, можно выбросить исключение или вернуть токен
    // ошибки
    std::cerr << "Error: Unrecognized character '" << m_currentChar << "'\n";
    advance();
  }

  return Token(Token::token_types::END, "");
}
void Lexer::advance() {
  m_position++;
  if (m_position >= m_size) {
    m_currentChar = '\0'; // Конец текста
  } else {
    m_currentChar = m_text[m_position];
  }
}
void Lexer::skipWhitespace() {
  while (m_currentChar != '\0' && std::isspace(m_currentChar)) {
    advance();
  }
}
Token Lexer::identifier() {
  std::string result;
  while (m_currentChar != '\0' &&
         (std::isalnum(m_currentChar) || m_currentChar == '_')) {
    result += m_currentChar;
    advance();
  }
  return Token(Token::token_types::ID, result);
}

Token Lexer::literal() {
  std::string result;
  while (m_currentChar != '\0' && std::isdigit(m_currentChar)) {
    result += m_currentChar;
    advance();
  }
  return Token(Token::token_types::LITERAL, result);
}
std::string Lexer::readKeyword() {
  std::string result;
  while (m_currentChar != '\0' && std::isalpha(m_currentChar)) {
    result += m_currentChar;
    advance();
  }
  return result;
}
} // namespace Core

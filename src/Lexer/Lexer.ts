import ErrorHandler from "../ErrorHandler/Handler";
import Token from "../Token/Token";
import { TokenType } from "../Token/TokenType";

export default class Lexer {
    private readonly source: string;
    private tokens: Token[] = [];

    private start: number = 0;
    private current: number = 0;
    private line: number = 1;


    constructor(source: string) {
        this.source = source;
    }

    public scanTokens() {
        while(!this.isAtEnd()) {
            this.start = this.current;
            this.scanToken();
        }

        this.tokens.push(new Token(TokenType.EOF, "", {}, this.line));

        return this.tokens;
    }

    private scanToken() {
        const c = this.advance();
        switch (c) {
          case '(': this.addToken(TokenType.LEFT_PAREN); break;
          case ')': this.addToken(TokenType.RIGHT_PAREN); break;
          case '{': this.addToken(TokenType.LEFT_BRACE); break;
          case '}': this.addToken(TokenType.RIGHT_BRACE); break;
          case ',': this.addToken(TokenType.COMMA); break;
          case '.': this.addToken(TokenType.DOT); break;
          case '-': this.addToken(TokenType.MINUS); break;
          case '+': this.addToken(TokenType.PLUS); break;
          case ';': this.addToken(TokenType.SEMICOLON); break;
          case '*': this.addToken(TokenType.STAR); break;
          default:
            ErrorHandler.error(this.line, "Unexpected character.");
            break;
        }
    }

    private advance() {
        return this.source.charAt(this.current++);
    }

    private addToken(type: TokenType, literal?: object) {

        if(!literal) literal = {};

        const text = this.source.substring(this.start, this.current);
        this.tokens.push(new Token(type, text, literal, this.line));
    }

    private isAtEnd(): boolean {
        return this.current >= this.source.length;
    }
}
// index.ts
import * as fs from "fs";
import Lexer from "./Lexer/Lexer";

export default class Eco {

    static hadError: Boolean = false;

    public main() {
        this.runFile("program.eco");
    }
    
    private runFile(path: string) {
        try {
            const input = fs.readFileSync(path, "utf8");
    
            this.run(input);
        } catch (error) {
            console.error("Error during file read:");
            console.error(error);
            process.exit(64);
        }
    }
    
    private run(input: string) {
        const lexer = new Lexer(input);
        const tokens = lexer.scanTokens();
        
        if(Eco.hadError) process.exit(65);

        for(const token of tokens) {
            console.log(token);
        }
    }
}
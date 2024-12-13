import Eco from "../Eco";

export default class ErrorHandler {
    public static error(line: number, message: string) {
        this.report(line, "", message);
    }

    private static report(line: number, where: string, message: string) {
        console.error(`[line: ${line}] Error${where}: ${message}`);
        Eco.hadError = true;
    }
}
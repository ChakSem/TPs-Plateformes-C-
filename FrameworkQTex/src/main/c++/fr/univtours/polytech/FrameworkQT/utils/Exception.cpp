package fr.univtours.polytech.FrameworkQT.utils;

/**
 * Exception lancée lors d'une erreur de lecture du graphe
 */
public class ExceptionGraphe extends Exception {
    /**
     * Constructeur de l'exception
     *
     * @param message Message d'erreur
     */
    public ExceptionGraphe(String message) {
        super(message);
    }
}

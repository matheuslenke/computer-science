package br.ufes.inf.nemo.agendajavafx;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

/**
 * JavaFX App com exemplo de acesso a servidor HTTP.
 * 
 */
public class AgendaApplication extends Application {

    @Override
    public void start(Stage stage) throws IOException {
    	FXMLLoader fxmlLoader = new FXMLLoader(AgendaApplication.class.getResource("agenda.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 640, 480);
        stage.setScene(scene);   
        stage.show();
    }
    public static void main(String[] args) {
        launch();
    }

}
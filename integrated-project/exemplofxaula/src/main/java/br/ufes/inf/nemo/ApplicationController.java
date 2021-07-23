package br.ufes.inf.nemo;

import javafx.fxml.FXML;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

public class ApplicationController {

	@FXML private TextField textField; 
	@FXML private TextArea textArea;
	
	public void handleEnterButton()
	{		
		String entradaUsuario = textField.getText();
		textArea.appendText(entradaUsuario+"\n");
		textField.clear();
		textField.requestFocus();
	}

	public void clearTextArea()
	{
		textArea.clear();
	}
	
	public void handleQuit()
	{
		System.exit(0);
	}
	
}

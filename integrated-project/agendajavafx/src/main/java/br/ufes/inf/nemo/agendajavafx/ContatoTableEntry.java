package br.ufes.inf.nemo.agendajavafx;

import javafx.beans.property.SimpleStringProperty;

/**
 * Classe necessária para representar o conteúdo da table view de contatos.
 * 
 * @author jpalmeida
 *
 */
public class ContatoTableEntry {
	private SimpleStringProperty nome;
	private SimpleStringProperty telefone;
	public ContatoTableEntry(String nome, String telefone)
	{
		this.nome=new SimpleStringProperty(nome);
		this.telefone=new SimpleStringProperty(telefone);
	}
    
	public SimpleStringProperty nomeProperty() {
        return nome;
    }
	public String getNome() {
		return nome.get();
	}
	public void setNome(String nome) {
		this.nome.set(nome);
	}
	public String getTelefone() {
		return telefone.get();
	}
	public void setTelefone(String telefone) {
		this.telefone.set(telefone);
	}
}

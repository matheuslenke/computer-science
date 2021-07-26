package br.ufes.inf.nemo.agenda.domain;

public class Contato {
	private long id;
	private String nome;
	private String telefone;
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public String getTelefone() {
		return telefone;
	}
	public void setTelefone(String telefone) {
		this.telefone = telefone;
	}


	public long getId() { return this.id; }
	public void setId(int id) {
		this.id = id;
	}
}

package br.ufes.inf.nemo.agenda.domain;

import java.util.LinkedList;
import java.util.List;

public class Agenda {
	private List<Contato> contatos = new LinkedList<>();

	public List<Contato> getContatos() {
		return contatos;
	}

	public void setContatos(List<Contato> contatos) {
		this.contatos = contatos;
	}
}

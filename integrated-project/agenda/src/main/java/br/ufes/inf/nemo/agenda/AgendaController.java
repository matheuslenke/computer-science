package br.ufes.inf.nemo.agenda;

import java.util.LinkedList;
import java.util.List;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

import br.ufes.inf.nemo.agenda.domain.*;

@RestController
public class AgendaController {

	private static Agenda agenda = new Agenda();
	
	@GetMapping("/contatos")
	public List<Contato> getAgenda(
			@RequestParam(name="nome",defaultValue="") String nome)
	{
		List<Contato> contatosFiltrados = new LinkedList<>();
		for(Contato c : agenda.getContatos())
		{
			if (c.getNome().contains(nome)) contatosFiltrados.add(c);
		}
		return contatosFiltrados;
	}
	
	@PostMapping("/contatos")
	public Contato postContato(@RequestBody Contato c)
	{
		int id = agenda.getContatosSize();
		c.setId(id + 1);
		agenda.getContatos().add(c);
		return c;
	}

	@GetMapping("/contatos/{id}")
	public Contato getContato(
			@PathVariable long id)
	{
		Contato contatoEncontrado;

		for(Contato c : agenda.getContatos())
		{
			if (c.getId() == id) {
				contatoEncontrado = c;
				return contatoEncontrado;
			}
		}
		return null;
	}

	@PutMapping("/contatos/{id}")
	public Contato updateContato(
			@PathVariable long id, @RequestBody Contato contato)
	{
		Contato contatoEncontrado = null;

		for(Contato c : agenda.getContatos())
		{
			if (c.getId() == id) {
				contatoEncontrado = c;
			}
		}
		if (contatoEncontrado != null) {
			contatoEncontrado.setNome(contato.getNome());
			contatoEncontrado.setTelefone(contato.getTelefone());
			return contatoEncontrado;
		}
		return null;
	}

	@DeleteMapping("/contatos/{id}")
	public List<Contato> deleteContato(
			@PathVariable long id)
	{
		Contato contatoEncontrado = null;
		List<Contato> novosContatos = new LinkedList<>();

		for(Contato c : agenda.getContatos())
		{
			if (c.getId() != id) {
				novosContatos.add(c);
			}
		}
		agenda.setContatos(novosContatos);
		return novosContatos;
	}
}

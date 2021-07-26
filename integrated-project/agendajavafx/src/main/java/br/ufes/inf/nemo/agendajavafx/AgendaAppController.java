package br.ufes.inf.nemo.agendajavafx;

import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;
import java.util.ArrayList;

import org.apache.http.HttpEntity;
import org.apache.http.ParseException;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.client.utils.URIBuilder;
import org.apache.http.entity.StringEntity;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;

import com.google.gson.Gson;

import br.ufes.inf.nemo.agenda.domain.Contato;
import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.stage.Modality;
import javafx.stage.Stage;

public class AgendaAppController  {
	@FXML private TextField textField;
	
	@FXML private TableView<ContatoTableEntry> tableView;
	@FXML private TableColumn<ContatoTableEntry, String> nomeCol;
	@FXML private TableColumn<ContatoTableEntry, String> telefoneCol;

	@FXML private TextField nomeTextField;
	@FXML private TextField telefoneTextField;

	private static Stage newWindow;
	
	/**
	 * Invocado quando o usuário seleciona Contato->Novo.
	 * 
	 */
	public void handleNew() throws IOException 
	{		
		newWindow = new Stage();
        newWindow.setTitle("Novo contato...");
        FXMLLoader fxmlLoader = new FXMLLoader(AgendaAppController.class.getResource("newdialog.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 344, 178);
        newWindow.setScene(scene);
        newWindow.initModality(Modality.APPLICATION_MODAL);
        newWindow.show();        
	}
	
	/**
	 * Invocado quando o usuário seleciona Contato->Sair.
	 * 
	 */
	public void handleQuit()
	{
		System.exit(0);
	}

	/**
	 * Invocado quando o usuário pressiona enter na caixa de busca.
	 * 
	 * Consulta o servidor por contatos incluindo no nome o texto na caixa de busca.
	 * 
	 */
	public void handleTextField() throws ParseException, IOException, URISyntaxException
	{
		String responseStr = null;

//		String url = "http://localhost:8080/contatos?nome="+textField.getText();
		/**
		 * enquanto a forma acima funciona para casos simples, se houver caracteres
		 * no textField como espaços ou '&' eles precisam ser processados 
		 * adequadamente na query string
		 * veja https://en.wikipedia.org/wiki/Query_string
		 */
		String baseUrl = "http://localhost:8080/contatos";
		URI uri = new URIBuilder(baseUrl)
			      .addParameter("nome", textField.getText())
			      .build();
		
		CloseableHttpClient httpclient = HttpClients.createDefault();
		HttpGet httpget = new HttpGet(uri);
		CloseableHttpResponse response = httpclient.execute(httpget);
		HttpEntity entity = response.getEntity();
		responseStr = EntityUtils.toString(entity);
		
		// processar a resposta
		Gson gson = new Gson();
		Contato[] contatos=gson.fromJson(responseStr, Contato[].class);
		
		// colocar a resposta na tabela
		ArrayList<ContatoTableEntry> contatosList = new ArrayList<ContatoTableEntry>();
		for(Contato c: contatos)
		{
			ContatoTableEntry e = new ContatoTableEntry(c.getNome(),c.getTelefone());
			contatosList.add(e);
		}
		nomeCol.setCellValueFactory(
                new PropertyValueFactory<>("nome"));
		telefoneCol.setCellValueFactory(
                new PropertyValueFactory<>("telefone"));	
		tableView.setItems(FXCollections.observableArrayList(contatosList));	
	}

	/**
	 * Invocado quando o usuário pressiona "Cancela" na janela de diálogo "Novo Contato".
	 * 
	 */
	public void handleCloseNew()
	{
		newWindow.close();
	}

	/**
	 * Invocado quando o usuário pressiona enter no nome do novo contato
	 * na janela de diálogo "Novo Contato".
	 * 
	 */
	public void handleEnterNomeTextField()
	{
		telefoneTextField.requestFocus();
	}	

	/**
	 * Invocado quando o usuário pressiona enter no telefone do novo contato
	 * na janela de diálogo "Novo Contato" ou no botão "Confirma".
	 * 
	 * Executa POST no servidor para incluir o novo contato.
	 * 
	 */
	public void handlePost() throws ClientProtocolException, IOException 
	{
		String responseStr = null;
		String url = "http://localhost:8080/contatos";
		CloseableHttpClient httpclient = HttpClients.createDefault();
		HttpPost httppost = new HttpPost(url);
		httppost.setHeader("Accept", "application/json");
		httppost.setHeader("Content-Type", "application/json");

		// prepara o novo contato
		Contato c = new Contato();
		c.setNome(nomeTextField.getText());
		c.setTelefone(telefoneTextField.getText());
		Gson gson = new Gson();
		String strEntity=gson.toJson(c);
		
		// envia o novo contato para o servidor
		HttpEntity requestEntity = new StringEntity(strEntity);
		httppost.setEntity(requestEntity);
		httpclient.execute(httppost);
		
		newWindow.close();
	}
	
	
}

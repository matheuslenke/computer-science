package br.ufes.inf.nemo.jpalmeida.covidbrazil;

import java.io.IOException;

import org.apache.http.HttpEntity;
import org.apache.http.ParseException;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;

import com.google.gson.Gson;

public class OWIDRepository {

	private TopLevelOWIDRepository owid;
	
	public OWIDRepository() throws IOException
	{
		// primeiro vamos baixar o arquivo
		String responseStr = null;
			String url = "https://covid.ourworldindata.org/data/owid-covid-data.json";
			CloseableHttpClient httpclient = HttpClients.createDefault();
			HttpGet httpget = new HttpGet(url);
			CloseableHttpResponse response = httpclient.execute(httpget);
			HttpEntity entity = response.getEntity();
			responseStr = EntityUtils.toString(entity);

		// obtém dados só para o Brasil, EUA
		Gson gson = new Gson();
		owid = gson.fromJson(responseStr, TopLevelOWIDRepository.class);
	}

	public TopLevelOWIDRepository getOwid() {
		return owid;
	}
}

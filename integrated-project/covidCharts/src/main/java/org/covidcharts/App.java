package org.covidcharts;

import br.ufes.inf.nemo.jpalmeida.covidbrazil.*;
import com.google.gson.Gson;
import org.apache.http.HttpEntity;
import org.apache.http.ParseException;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;
import org.jfree.data.xy.XYDataset;

import java.awt.*;
import java.io.IOException;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        // primeiro vamos baixar o arquivo
        String responseStr = null;
        try {
            String url = "https://covid.ourworldindata.org/data/owid-covid-data.json";
            CloseableHttpClient httpclient = HttpClients.createDefault();
            HttpGet httpget = new HttpGet(url);
            System.out.println("Downloading...");
            CloseableHttpResponse response = httpclient.execute(httpget);
            HttpEntity entity = response.getEntity();
            System.out.println("...done!");
            responseStr = EntityUtils.toString(entity);
        } catch (ParseException | IOException e1) {
            // TODO Auto-generated catch block
            e1.printStackTrace();
            System.exit(1);
        }

        // obtém dados só para o Brasil e EUA
        Gson gson = new Gson();
        TopLevelOWIDRepository owid = gson.fromJson(responseStr, TopLevelOWIDRepository.class);

//        Criação do Gráfico

        XYDataset dataSet = LineChart.createDataset(owid.BRA, "BRA", owid.USA, "USA");
        LineChart chart = new LineChart(dataSet);

        EventQueue.invokeLater(() -> {
            chart.setVisible(true);
        });

    }
}

package com.mycompany.app;

import java.io.*;
import java.net.ProtocolException;
import java.util.Map;
import java.lang.reflect.Type;
import java.net.URL;
import java.net.HttpURLConnection;

import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

public class App
{

    public static void main(String[] args )  {
        final String arg0 = args[0].toLowerCase().trim();

        if (arg0.compareTo("-f") == 0) {
            String filename = args[1];
            try {
                processLocalJson(filename);
            } catch (Exception err) {
                System.out.println(err.getMessage());
            }
        } else if(arg0.compareTo("-http") == 0) {
            try {
                processOnlineJson(args[1]);
            } catch (Exception err) {
                System.out.println(err.getMessage());
            }
        }


    }

    /**
     * Process JSON from local file
     * @param filename : Path to the local file, starting from root
     * @throws FileNotFoundException: When invalid path is received
     */
    private static void processLocalJson(String filename) throws FileNotFoundException {
        File file = new File(filename);
        Reader in = new FileReader(file);
        Gson gson = new Gson();
        final Type countryType = new TypeToken<Map<String,Country>>(){}.getType();
        Map<String,Country> countries = gson.fromJson(in, countryType);

        countries.values().stream().sorted(Country::compareTo).forEach(System.out::println);
    }

    /**
     * Process JSON from GET request
     * @throws IOException: When an error happens in the GET request
     */
    private static void processOnlineJson(String getUrl) throws IOException {
        URL url = new URL(getUrl);
        HttpURLConnection con = (HttpURLConnection) url.openConnection();
        con.setRequestMethod("GET");
        int responseCode = con.getResponseCode();
        System.out.println("Making http Request");
        if (responseCode == HttpURLConnection.HTTP_OK) { // success
            BufferedReader in = new BufferedReader(new InputStreamReader(
                    con.getInputStream()));

            Gson gson = new Gson();
            final Type countryType = new TypeToken<Map<String,Country>>(){}.getType();
            Map<String,Country> countries = gson.fromJson(in, countryType);

            countries.values().stream().sorted(Country::compareTo).forEach(System.out::println);
        } else {
            System.out.println("GET request returned fail code status");
        }
    }

}

# Como rodar a aplicação

### Instalar dependencies
```
$ mvn install
```

### Compilar
```
$ mvn package
```

### Rodar .jar de um arquivo local
- From root directory
- First argument is path to json file
```
$ java -cp ./target/gson-exercise-app-1.0-SNAPSHOT-jar-with-dependencies.jar com.mycompany.app.App -f ./src/main/resources/owid-covid-data.json
```

### Rodar .jar pegando json de uma URL
```
$ java -cp ./target/gson-exercise-app-1.0-SNAPSHOT-jar-with-dependencies.jar com.mycompany.app.App -http https://covid.ourworldindata.org/data/owid-covid-data.json
```
package com.mycompany.app;

import java.util.ArrayList;

public class Country implements Comparable {
    private String continent;
    private String location;
    private Double population;
    private Double population_density;
    private Double median_age;
    private Double aged_65_older;
    private Double aged_70_older;
    private Double gdp_per_capita;
    private Double cardiovasc_death_rate;
    private ArrayList<Data> data;

    public Double getNewDeathsSmoothedPerMillion() {
        Double deathsData = this.data.get(this.data.size() - 1).getNewDeathsSmoothedPerMillion();
        if (deathsData == null) {
            return 0.0;
        }
        return deathsData;
    }

    @Override
    public String toString() {
        Double numberOfDeaths = this.getNewDeathsSmoothedPerMillion();
        return this.location + ": " + numberOfDeaths.toString();
    }

    @Override
    public int compareTo( Object objectToCompare) {
        Country country = (Country) objectToCompare;
        Double DataA = this.getNewDeathsSmoothedPerMillion();
        Double DataB = country.getNewDeathsSmoothedPerMillion();
        return Double.compare(DataB, DataA);
    }

}

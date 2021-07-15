package org.covidcharts;
import br.ufes.inf.nemo.jpalmeida.covidbrazil.CasesDetail;
import br.ufes.inf.nemo.jpalmeida.covidbrazil.CountryDetail;
import br.ufes.inf.nemo.jpalmeida.covidbrazil.OWIDRepository;
import br.ufes.inf.nemo.jpalmeida.covidbrazil.TopLevelOWIDRepository;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.block.BlockBorder;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.chart.plot.XYPlot;
import org.jfree.chart.renderer.xy.XYLineAndShapeRenderer;
import org.jfree.chart.title.TextTitle;
import org.jfree.data.xy.XYDataset;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;

import javax.swing.BorderFactory;
import javax.swing.JFrame;
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;

public class LineChart extends JFrame {

    public LineChart(XYDataset dataset) {

        initUI(dataset);
    }

    private void initUI(XYDataset dataset) {
        JFreeChart chart = createChart(dataset);

        ChartPanel chartPanel = new ChartPanel(chart);
        chartPanel.setBorder(BorderFactory.createEmptyBorder(15, 15, 15, 15));
        chartPanel.setBackground(Color.white);
        add(chartPanel);

        pack();
        setTitle("Line chart");
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static XYDataset createDataset(CountryDetail country1, String key1, CountryDetail country2, String key2) {
        var series1 = new XYSeries(key1);

        int index = 0;
        for (CasesDetail data : country1.data) {
            series1.add(index, data.new_deaths_smoothed_per_million);
            index++;
        }
        var series2 = new XYSeries(key2);

        index = 0;
        for (CasesDetail data : country2.data) {
            series2.add(index, data.new_deaths_smoothed_per_million);
            index++;
        }


        var dataset = new XYSeriesCollection();
        dataset.addSeries(series1);
        dataset.addSeries(series2);

        return dataset;
    }

    private JFreeChart createChart(XYDataset dataset) {

        JFreeChart chart = ChartFactory.createXYLineChart(
                "Média Móvel de mortes por milhão de habitantes",
                "Data",
                "Número de Mortes por Milhão de Habitantes",
                dataset,
                PlotOrientation.VERTICAL,
                true,
                true,
                false
        );

        XYPlot plot = chart.getXYPlot();

        var renderer = new XYLineAndShapeRenderer();
        renderer.setSeriesPaint(0, Color.GREEN);
        renderer.setSeriesStroke(0, new BasicStroke(2.0f));
        renderer.setSeriesPaint(1, Color.RED);
        renderer.setSeriesStroke(1, new BasicStroke(2.0f));

        plot.setRenderer(renderer);
        plot.setBackgroundPaint(Color.white);

        plot.setRangeGridlinesVisible(true);
        plot.setRangeGridlinePaint(Color.BLACK);

        plot.setDomainGridlinesVisible(true);
        plot.setDomainGridlinePaint(Color.BLACK);

        chart.getLegend().setFrame(BlockBorder.NONE);

        chart.setTitle(new TextTitle("Média Móvel de mortes por milhão de habitantes",
                        new Font("Serif", java.awt.Font.BOLD, 18)
                )
        );

        return chart;
    }

}
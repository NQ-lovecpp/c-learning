#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double calculateMean(const vector<double>& data)
{
    double sum = 0.0;
    for (const double& value : data)
    {
        sum += value;
    }
    return sum / data.size();
}

double calculateTypeAUncertainty(const vector<double>& data, double mean)
{
    double variance = 0.0;
    for (const double& value : data)
    {
        variance += pow(value - mean, 2);
    }
    double stdDeviation = sqrt(variance / (data.size() - 1));
    return stdDeviation / sqrt(data.size());
}

double calculateTypeBUncertainty(const vector<double>& data)
{
    // You can implement the calculation of Type B uncertainty here.
    // This depends on the specific nature of your measurements.
    // For example, it could involve instrument specifications or calibration data.
    // Replace this with the appropriate calculation for your data.
    return 0.02/(sqrt(3));
}

double calculateCombinedUncertainty(double typeAUncertainty, double typeBUncertainty)
{
    return sqrt(pow(typeAUncertainty, 2) + pow(typeBUncertainty, 2));
}

int main()
{
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> data(n);

    cout << "Enter the data points:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> data[i];
    }

    double mean = calculateMean(data);
    double typeAUncertainty = calculateTypeAUncertainty(data, mean);
    double typeBUncertainty = calculateTypeBUncertainty(data);
    double combinedUncertainty = calculateCombinedUncertainty(typeAUncertainty, typeBUncertainty);

    cout << "Mean: " << mean << endl;
    cout << "Type A Uncertainty (Ua): " << typeAUncertainty << endl;
    cout << "Type B Uncertainty (Ub): " << typeBUncertainty << endl;
    cout << "Combined Uncertainty (Ud): " << combinedUncertainty << endl;
    //// 四舍六入五取偶的结果
    //cout << "Rounded Values:" << endl;
    //for (int i = 0; i < n; ++i) {
    //    int integerPart = static_cast<int>(data[i]);
    //    double decimalPart = data[i] - integerPart;
    //    int roundedValue;

    //    if (decimalPart < 0.5) {
    //        // Four-Six rounding
    //        roundedValue = static_cast<int>(data[i] + 0.5);
    //    }
    //    else if (decimalPart > 0.5) {
    //        // Six rounding
    //        roundedValue = static_cast<int>(ceil(data[i]));
    //    }
    //    else {
    //        // Five-Rounding-Even
    //        if (integerPart % 2 == 0) {
    //            roundedValue = static_cast<int>(data[i] + 0.5);
    //        }
    //        else {
    //            roundedValue = static_cast<int>(ceil(data[i]));
    //        }
    //    }

    //    cout << "Original Value: " << data[i] << " Rounded Value: " << roundedValue << endl;
    //}

    return 0;
}
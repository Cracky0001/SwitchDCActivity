using System.Windows;

namespace SwitchDcrpc.Wpf;

public partial class SettingsWindow : Window
{
    public SettingsWindow(bool startWithWindows, bool connectOnStartup, bool showGithubButton, bool showBatteryStatus)
    {
        InitializeComponent();
        StartWithWindowsCheckBox.IsChecked = startWithWindows;
        ConnectOnStartupCheckBox.IsChecked = connectOnStartup;
        ShowGithubButtonCheckBox.IsChecked = showGithubButton;
        ShowBatteryStatusCheckBox.IsChecked = showBatteryStatus;
    }

    public bool StartWithWindows => StartWithWindowsCheckBox.IsChecked == true;

    public bool ConnectOnStartup => ConnectOnStartupCheckBox.IsChecked == true;
    public bool ShowGithubButton => ShowGithubButtonCheckBox.IsChecked == true;
    public bool ShowBatteryStatus => ShowBatteryStatusCheckBox.IsChecked == true;

    private void SaveButton_Click(object sender, RoutedEventArgs e)
    {
        DialogResult = true;
        Close();
    }
}

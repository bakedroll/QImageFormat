#include <QApplication>
#include <QFileDialog>

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  QFileDialog dialog;
  dialog.setFileMode(QFileDialog::Directory);
  dialog.setOption(QFileDialog::ShowDirsOnly);

  if (dialog.exec())
  {
    const QDir directory(dialog.selectedFiles()[0]);
    const auto imageFiles = directory.entryList(QStringList() << "*.png" << "*.PNG", QDir::Files);

    for (const auto& file : imageFiles)
    {
      const auto filepath = directory.filePath(file);
      QImage image(filepath);
      if (!image.isNull())
      {
        printf("Fixed image file %s\n", file.toStdString().c_str());
        (void) image.save(filepath, "PNG");
      }
      else
      {
        printf("Could not open image file %s\n", file.toStdString().c_str());
      }
    }
  }

  return 0;
}
#ifndef ATLAS_IO_FILEIMAGESOURCE_HPP
#define ATLAS_IO_FILEIMAGESOURCE_HPP

#include "common.hpp"
#include "imagesource.hpp"
#include "atlas/core/image.hpp"
#include "atlas/core/imageformat.hpp"

namespace atlas::io
{
    using namespace atlas::core;

    // A data source that reads from a simple, non georeferenced file
    class FileImageSource final : public ImageSource
    {
    public:
        FileImageSource(Region, const std::string filename);

        std::future<Response<Image>> get(Request<Region>) override;

        inline std::string filename() const noexcept { return _filename; }

        Region region() const noexcept { return _region; }

    private:
        Region _region;
        std::string _filename;
        std::shared_ptr<Image> _image;
    };
}

#endif // ATLAS_IO_FILEIMAGESOURCE_HPP
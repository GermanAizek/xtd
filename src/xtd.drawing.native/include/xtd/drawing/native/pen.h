#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <xtd/static.h>
#include <xtd/drawing_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class pen;
    /// @endcond
    
    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains pen native API.
      /// @par Namespace
      /// xtd::drawing::native
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ pen final static_ {
        friend xtd::drawing::pen;
      protected:
        /// @name Protected methods
        
        /// @{
        /// @brief Creates a pen.
        /// @return The created pen handle.
        /// @warning Internal use only
        static intptr_t create();
        
        /// @brief Sets solid color pen with specified color, width, dash offset and dash array.
        /// @param pen the pen handle.
        /// @param a The alpha component of the color.
        /// @param r The red component of the color.
        /// @param g The green component of the color.
        /// @param b The blue component of the color.
        /// @param width The width of the pen in pixels.
        /// @param dash_offset The offset of the dash.
        /// @param dashes A dash array that represent the format of dash. If the array of dashes is empty then the pen is a solid type.
        /// @warning Internal use only
        static void solid_color(intptr_t pen, uint8_t a, uint8_t r, uint8_t g, uint8_t b, float width, float dash_offset, std::vector<float> dashes);
        
        /// @brief Sets hatch fill pen with specified hatch fill brush and width.
        /// @param pen the pen handle.
        /// @param brush the hatch brush handle.
        /// @param width The width of the pen in pixels.
        /// @warning Internal use only
        static void hatch_fill(intptr_t pen, intptr_t brush, float width);
        
        /// @brief Sets conical gradient pen with specified conical gradient brush and width.
        /// @param pen the pen handle.
        /// @param brush the conical gradient brush handle.
        /// @param width The width of the pen in pixels.
        /// @warning Internal use only
        static void conical_gradient(intptr_t pen, intptr_t brush, float width);
        
        /// @brief Sets the cap style used at the end of lines drawn with the pen.
        /// @param pen the pen handle.
        /// @param value A value that represents the cap style used at the end of lines drawn with the pen (see line_saps.h for more information).
        /// @warning Internal use only
        static void end_cap(intptr_t pen, int32_t line_cap);
        
        /// @brief Sets linear gradient pen with specified linear gradient brush and width.
        /// @param pen the pen handle.
        /// @param brush the linear gradient brush handle.
        /// @param width The width of the pen in pixels.
        /// @warning Internal use only
        static void linear_gradient(intptr_t pen, intptr_t brush, float width);
        
        /// @brief Sets the join style for the ends of two consecutive lines drawn with the pen.
        /// @param pen the pen handle.
        /// @param line_join A value that represents the join style for the ends of two consecutive lines drawn with the pen (see line_joins.h for more information).
        /// @warning Internal use only
        static void line_join(intptr_t pen, int32_t line_join);
        
        /// @brief Sets the limit of the thickness of the join on a mitered corner.
        /// @param pen the pen handle.
        /// @param miter_limit The limit of the thickness of the join on a mitered corner.
        /// @warning Internal use only
        static void miter_limit(intptr_t pen, float miter_limit);
        
        /// @brief Sets radial gradient pen with specified radial gradient brush and width.
        /// @param pen the pen handle.
        /// @param brush the radial gradient brush handle.
        /// @param width The width of the pen in pixels.
        /// @warning Internal use only
        static void radial_gradient(intptr_t pen, intptr_t brush, float width);
        
        /// @brief Sets the cap style used at the start of lines drawn with the pen.
        /// @param pen the pen handle.
        /// @param value A value that represents the cap style used at the start of lines drawn with the pen (see line_saps.h for more information).
        /// @warning Internal use only
        static void start_cap(intptr_t pen, int32_t line_cap);
        
        /// @brief Sets texture fill pen with specified texture fill brush and width.
        /// @param pen the pen handle.
        /// @param brush the texture fill brush handle.
        /// @param width The width of the pen in pixels.
        /// @warning Internal use only
        static void texture_fill(intptr_t pen, intptr_t brush, float width);
        
        /// @brief Destroys a pen.
        /// @param pen The pen handle to destroy.
        /// @warning Internal use only
        static void destroy(intptr_t pen);
        /// @}
      };
    }
  }
}

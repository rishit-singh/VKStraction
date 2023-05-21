#include "vertex.hpp"

VKStraction::Vector2D::Vector2D(int x, int y) :  X(x), Y(y)
{
}

VKStraction::Vertex2D::Vertex2D(VKStraction::Vector2D position, VKStraction::RGBA color, VKStraction::Vector2D textureCoordinates) : Position(position), Color(color), TextureCoordinates(textureCoordinates)
{
}

VKStraction::RGBA::RGBA(int r, int g, int b, int a) : R(r), G(g), B(b), A(a)
{
}

VKStraction::RGBA VKStraction::Colors[5] = {RGBA(255, 0, 0), RGBA(0, 255, 0),
                                         RGBA(0, 0, 255), RGBA(255, 255, 255),
                                         RGBA(0, 0, 0)};

VKStraction::Vector2D VKStraction::Vector2D::operator +(VKStraction::Vector2D rhs)
{
    return Vector2D(this->X + rhs.X, this->Y + rhs.Y);
}

VKStraction::Vector2D VKStraction::Vector2D::operator -(VKStraction::Vector2D rhs)
{
    return Vector2D(this->X - rhs.X, this->Y - rhs.Y);
}

VKStraction::Vector2D VKStraction::Vector2D::operator *(VKStraction::Vector2D rhs)
{
    return Vector2D(this->X * rhs.X, this->Y * rhs.Y);
}

VKStraction::Vector2D VKStraction::Vector2D::operator /(VKStraction::Vector2D rhs)
{
    return Vector2D(this->X / rhs.X, this->Y / rhs.Y);
}

VKStraction::Vector2D &VKStraction::Vector2D::operator +=(VKStraction::Vector2D difference)
{
    this->X += difference.X;
    this->Y += difference.Y;

    return *this;
}


VKStraction::Vector2D &VKStraction::Vector2D::operator -=(VKStraction::Vector2D difference)
{
    this->X -= difference.X;
    this->Y -= difference.Y;

    return *this;
}

VKStraction::Vector2D &VKStraction::Vector2D::operator *=(VKStraction::Vector2D difference)
{
    this->X *= difference.X;
    this->Y *= difference.Y;

    return *this;
}

VKStraction::Vector2D &VKStraction::Vector2D::operator /=(VKStraction::Vector2D difference)
{
    this->X /= difference.X;
    this->Y /= difference.Y;

    return *this;
}

VKStraction::Vector2D VKStraction::Vector2D::operator +(int rhs)
{
    return Vector2D(this->X + rhs, this->Y + rhs);
}

VKStraction::Vector2D VKStraction::Vector2D::operator -(int rhs)
{
    return Vector2D(this->X - rhs, this->Y - rhs);
}

VKStraction::Vector2D VKStraction::Vector2D::operator *(int rhs)
{
    return Vector2D(this->X * rhs, this->Y * rhs);
}

VKStraction::Vector2D VKStraction::Vector2D::operator /(int rhs)
{
    return Vector2D(this->X / rhs, this->Y / rhs);
}

VKStraction::Vector2D &VKStraction::Vector2D::operator +=(int rhs)
{
    this->X += rhs;
    this->Y += rhs;

    return *this;
}

VKStraction::Vector2D &VKStraction::Vector2D::operator -=(int rhs)
{
    this->X -= rhs;
    this->Y -= rhs;

    return *this;
}

VKStraction::Vector2D &VKStraction::Vector2D::operator *=(int rhs)
{
    this->X *= rhs;
    this->Y *= rhs;

    return *this;
}

VKStraction::Vector2D &VKStraction::Vector2D::operator /=(int rhs)
{
    this->X /= rhs;
    this->Y /= rhs;

    return *this;
}

bool VKStraction::Vector2D::operator ==(VKStraction::Vector2D& vector)
{
    return (this->X = vector.X && this->Y == vector.Y );
}

int VKStraction::Vector2D::DistanceFrom(VKStraction::Vector2D& vector)
{
    return (sqrt(pow(vector.X - this->X, 2)) + pow(vector.Y - this->Y, 2));
}

double VKStraction::Vector2Df::DistanceFrom(VKStraction::Vector2Df& vector)
{
    return (sqrt(pow(vector.X - this->X, 2)) + pow(vector.Y - this->Y, 2));
}

//-------//

VKStraction::Vector2Df::Vector2Df(double x, double y) :  X(x), Y(y)
{
}

VKStraction::Vertex2Df::Vertex2Df(Vector2Df position, RGBA color, Vector2Df textureCoordinates) : Position(position), Color(color), TextureCoordinates(textureCoordinates)
{
}

VKStraction::Vector2Df &VKStraction::Vector2Df::operator +=(Vector2Df difference)
{
    this->X += difference.X;
    this->Y += difference.Y;

    return *this;
}

VKStraction::Vector2Df &VKStraction::Vector2Df::operator -=(Vector2Df difference)
{
    this->X -= difference.X;
    this->Y -= difference.Y;

    return *this;
}

VKStraction::Vector2Df &VKStraction::Vector2Df::operator *=(Vector2Df difference)
{
    this->X *= difference.X;
    this->Y *= difference.Y;

    return *this;
}

VKStraction::Vector2Df &VKStraction::Vector2Df::operator /=(Vector2Df difference)
{
    this->X /= difference.X;
    this->Y /= difference.Y;

    return *this;
}

VKStraction::Vector2Df VKStraction::Vector2Df::operator +(double rhs)
{
    return Vector2Df(this->X + rhs, this->Y + rhs);
}

VKStraction::Vector2Df VKStraction::Vector2Df::operator -(double rhs)
{
    return Vector2Df(this->X - rhs, this->Y - rhs);
}

VKStraction::Vector2Df VKStraction::Vector2Df::operator *(double rhs)
{
    return Vector2Df(this->X * rhs, this->Y * rhs);
}

VKStraction::Vector2Df VKStraction::Vector2Df::operator /(double rhs)
{
    return Vector2Df(this->X / rhs, this->Y / rhs);
}

VKStraction::Vector2Df &VKStraction::Vector2Df::operator +=(double rhs)
{
    this->X += rhs;
    this->Y += rhs;

    return *this;
}

VKStraction::Vector2Df &VKStraction::Vector2Df::operator -=(double rhs)
{
    this->X -= rhs;
    this->Y -= rhs;

    return *this;
}

VKStraction::Vector2Df &VKStraction::Vector2Df::operator *=(double rhs)
{
    this->X *= rhs;
    this->Y *= rhs;

    return *this;
}

VKStraction::Vector2Df &VKStraction::Vector2Df::operator /=(double rhs)
{
    this->X /= rhs;
    this->Y /= rhs;

    return *this;
}

bool VKStraction::Vector2Df::operator ==(VKStraction::Vector2Df &vector)
{
    return (this->X == vector.X && this->Y == vector.Y);
}

bool VKStraction::Vector2Df::operator ==(const VKStraction::Vector2Df &vector) const
{
    return (this->X == vector.X && this->Y == vector.Y);
}

SDL_Vertex VKStraction::Vertex2Df::GetSDLVertex()
{
    return {
        SDL_FPoint { (float)this->Position.X, (float)this->Position.Y },
        SDL_Color { (uint8_t)this->Color.R, (uint8_t)this->Color.B, (uint8_t)this->Color.G, (uint8_t)this->Color.A },
        SDL_FPoint { (float)this->TextureCoordinates.X, (float)this->TextureCoordinates.Y }
    };
}

SDL_FPoint VKStraction::Vertex2Df::GetSDLPoint()
{
    return SDL_FPoint { (float)this->Position.X, (float)this->Position.Y };
}

bool VKStraction::Vertex2Df::Equals(VKStraction::Vertex2Df& vertex)
{
    return (this->Position == vertex.Position &&
            this->Color == vertex.Color &&
            this->TextureCoordinates == vertex.TextureCoordinates);
}

bool VKStraction::Vertex2Df::Equals(const VKStraction::Vertex2Df& vertex) const
{
  return (this->Position == vertex.Position &&
          this->Color == vertex.Color &&
          this->TextureCoordinates == vertex.TextureCoordinates);
}


bool VKStraction::Vertex2Df::operator ==(VKStraction::Vertex2Df &vertex)
{
    return this->Equals(vertex);
}

bool VKStraction::Vertex2Df::operator ==(const VKStraction::Vertex2Df &vertex) const
{
    return this->Equals(vertex);
}

bool VKStraction::RGBA::operator==(VKStraction::RGBA &rgba)
{
  return (this->R == rgba.R &&
          this->G == rgba.G &&
          this->B == rgba.B &&
          this->A == rgba.A);
}

bool VKStraction::RGBA::operator==(const VKStraction::RGBA &rgba) const
{
  return (this->R == rgba.R &&
          this->G == rgba.G &&
          this->B == rgba.B &&
          this->A == rgba.A);
}
